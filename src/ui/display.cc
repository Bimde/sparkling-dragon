#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <mutex>

#include "display.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "window.h"

using namespace std;

namespace {
  std::mutex mtx;
  int nextBlockGridWidth = 4;
  int nextBlockGridHeight = 2;
}

XDisplay::XDisplay(Quadris* game) : 
  window{WINDOW_WIDTH, WINDOW_HEIGHT},
  tileToColour{
    {'I', XWindow::Gray},
    {'J', XWindow::Red},
    {'L', XWindow::Green},
    {'O', XWindow::Blue},
    {'S', XWindow::Cyan},
    {'Z', XWindow::Purple},
    {'T', XWindow::Teal},
    {' ', XWindow::White},
    {'?', XWindow::Black},
    {'*', XWindow::Brown}
  }, 
  game{game},
  lastState{game->getState()}
  {
    calculateDimensions(lastState.gameState);

    if (!window.isInitialized()) {
      game->detach(this);
      return;
    }

    // Forcefully draw all fields and the board 
    // (without minimizing redrawing, since nothing is drawn yet)
    updateDisplay(true);
  }

XDisplay::~XDisplay() {}

void XDisplay::notify() {
  updateDisplay(false);
}

// Uses height and width of contained XWindow by maximize grid size
void XDisplay::calculateDimensions(const GameState& state) {
  int noRows = state.board.size();
  int noCols = state.board[0].size();

  // Subtracting the height for the fields from the available height for the grid
  int availableHeight = window.getHeight() - (NO_FIELDS + 1) * (PADDING + FIELD_HEIGHT) - PADDING;
  int availableWidth = window.getWidth() - 2 * PADDING;

  // X and Y starting points of the grid
  yStart = (NO_FIELDS + 1) * (PADDING + FIELD_HEIGHT);
  xStart = PADDING;

  // Maximum grid block side length based of width and height
  int height = availableHeight / noRows, width = availableWidth / noCols;

  // Set the maximum sideLength that allows the blocks to be squares
  if (height > width) { 
    sideLength = width;
    yStart += ((availableHeight - noRows * sideLength) / 2);
  } else {
    sideLength = height;
    xStart += ((availableWidth - sideLength * noCols) / 2);
  }
}

// Called to update the display using the current state.
// Can force redrawing everything by passing in redraw=true
void XDisplay::updateDisplay(bool redraw) {
  // Prevent multiple threads from updating the display at the same time
  mtx.lock();

  if (game == nullptr) {
    return;
  }

  QuadrisState state = game->getState();
  if (state.gameState.isGameOver) {
    drawGameOver(state.gameState, redraw);
  } else {
    drawFields(state, redraw);
    drawBoard(state.gameState, redraw);
    drawNextBlock(state.gameState, redraw);
  }

  // Saving a copy of the last state for comparison to mnimize redrawing
  lastState = state;
  mtx.unlock();
}


// Drawboard, then overlay all empty squares in the block with a non-white colour to show game over
void XDisplay::drawGameOver(const GameState& state, bool redraw) {
  if (!redraw && lastState.gameState.isGameOver) {
    return;
  }

  drawBoard(state, redraw);
  
  int noRows = state.board.size();
  int noCols = state.board[0].size();

  for (int i = 0; i < noRows; ++i) {
    for (int j = 0; j < noCols; ++j) {
      if (state.board[i][j] == EMPTY) {
        window.fillRectangleWithBorder(xStart + j * sideLength, yStart + i * sideLength, 
          sideLength, sideLength, GAME_OVER_COLOUR, BORDER_WIDTH);
      }
    }
  }
}

// Points in the block objects are in cartesian form, i.e. 0 at the bottom, 
// whereas he grid is drawn using array indices, 0 at the top
int cartesianPointToArray(int size, int x) {
  return (size - 1) - x;
}

void XDisplay::drawNextBlock(const GameState& state, bool redraw) {
  // If the next block is null, we want to erase the old block that was drawn
  if (redraw || state.nextBlock == nullptr ||
    lastState.gameState.nextBlock->getType() != state.nextBlock->getType()) {

    // Using xMid to allign the next block to the right side of the center
    int xMid = window.getWidth() / 2;
    drawField("Next Block: ", 2, xMid + NEXT_BLOCK_TEXT_START);

    for (int row = 0; row < nextBlockGridHeight; ++row) {
      for (int col = 0; col < nextBlockGridWidth; ++col) {
        window.fillRectangleWithBorder(xMid + NEXT_BLOCK_START + col * sideLength, 
          PADDING + FIELD_HEIGHT + row * sideLength, sideLength, 
          sideLength, XWindow::White, BORDER_WIDTH);
      }
    }

    if (state.nextBlock == nullptr) {
      return;
    }

    Point bottomLeft = state.nextBlock->getBottomLeft();
    for (Point p : state.nextBlock->pointsOnBoard()) {
      // Subtract the bottom left point from the cordiantes to get just the offsets
      int row = cartesianPointToArray(nextBlockGridHeight, p.y - bottomLeft.y);
      int col = p.x - bottomLeft.x;

      window.fillRectangleWithBorder(xMid + NEXT_BLOCK_START + col * sideLength, 
          PADDING + FIELD_HEIGHT + row * sideLength, sideLength, 
          sideLength, tileToColour[state.nextBlock->getType()], BORDER_WIDTH);
    }
  }
}

// Draw the grid, only redrawing what is needed
void XDisplay::drawBoard(const GameState& state, bool redraw) {
  int noRows = state.board.size();
  int noCols = state.board[0].size();

  for (int i = 0; i < noRows; ++i) {
    for (int j = 0; j < noCols; ++j) {
      if (redraw || state.board[i][j] != lastState.gameState.board[i][j]) {
        window.fillRectangleWithBorder(xStart + j * sideLength, yStart + i * sideLength, 
          sideLength, sideLength, tileToColour[state.board[i][j]], BORDER_WIDTH);
      }
    }
  }
}

// Draw the fields, only redrawing what is needed
void XDisplay::drawFields(const QuadrisState& state, bool redraw) {
  if (redraw || state.highScore != lastState.highScore) {
    drawHighScore(state.highScore);
  }
  if (redraw || state.gameState.score != lastState.gameState.score) {
    drawScore(state.gameState.score);
  }
  if (redraw || state.gameState.currentLevel != lastState.gameState.currentLevel) {
    drawCurrentLevel(state.gameState.currentLevel);
  }
}

void XDisplay::drawHighScore(int highScore) {
  drawField("High Score: " + to_string(highScore), 1, xStart);
}

void XDisplay::drawCurrentLevel(int currentLevel) {
  drawField("Current Level: " + to_string(currentLevel), 2, xStart);
}

void XDisplay::drawScore(int score) {
  drawField("Score: " + to_string(score), 3, xStart);
}

void XDisplay::drawField(string text, int row, int xOffset) {
  // Covering up old text
  window.fillRectangle(xOffset, PADDING + (PADDING + FIELD_HEIGHT) * row, 
    text.length() * CHAR_WIDTH, FIELD_HEIGHT, XWindow::White);
  
  // Draw the new text
  window.drawString(xOffset, (PADDING + FIELD_HEIGHT) * (row + 1), text);
}
