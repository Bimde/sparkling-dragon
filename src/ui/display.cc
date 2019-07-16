#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <unistd.h>
#include <mutex>

#include "display.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "window.h"

// XDisplay::XDisplay(std::weak_ptr<Game> game): game{game} {
//   Xwindow window{512, 512 / 2 * 3};
// }

using namespace std;

namespace {
  std::mutex mtx;
}

XDisplay::XDisplay(std::weak_ptr<Quadris> game) : 
  window{WINDOW_WIDTH, WINDOW_HEIGHT},
  tileToColour{
    {'I', Xwindow::Gray},
    {'J', Xwindow::Red},
    {'L', Xwindow::Green},
    {'O', Xwindow::Blue},
    {'S', Xwindow::Cyan},
    {'Z', Xwindow::Purple},
    {'T', Xwindow::Teal},
    {' ', Xwindow::White},
    {'?', Xwindow::Black},
    {'*', Xwindow::Brown}
  }, 
  game{game},
  lastState{game.lock()->getState()}
  {
    calculateDimensions(lastState.gameState);
    updateDisplay(true);
  }

XDisplay::~XDisplay() {}

void XDisplay::notify() {
  std::cout << "display notified" << std::endl;
  updateDisplay(false);
}

void XDisplay::calculateDimensions(const GameState& state) {
  int noRows = state.board.size();
  int noCols = state.board[0].size();
  int availableWidth = window.getWidth() - 2 * PADDING;
  int availableHeight = window.getHeight() - (NO_FIELDS + 1) * (PADDING + FIELD_HEIGHT) - PADDING;
  yStart = (NO_FIELDS + 1) * (PADDING + FIELD_HEIGHT);
  xStart = PADDING;
  int height = availableHeight / noRows, width = availableWidth / noCols;

  if (height > width) { 
    sideLength = width;
    yStart += ((availableHeight - noRows * sideLength) / 2);
  } else {
    sideLength = height;
    xStart += ((availableWidth - sideLength * noCols) / 2);
  }
}

void XDisplay::updateDisplay(bool redraw) {
  //window.drawString(15, y++, "Update");
  //window.fillRectangle(y, y, 50, 50, y % 5);
  mtx.lock();

  if (game.expired()) {
    cout << "Quadris pointer expired" << endl;
    return;
  }

  QuadrisState state = game.lock()->getState();
  drawFields(state, redraw);
  drawBoard(state.gameState, redraw);
  drawNextBlock(state.gameState, redraw);
  lastState = state;

  mtx.unlock();
}

void XDisplay::drawNextBlock(const GameState& state, bool redraw) {

  if (redraw || state.nextBlock == nullptr ||
    lastState.gameState.nextBlock->getType() != state.nextBlock->getType()) {
    cout << "Drawing next block:" << endl;

    int xMid = window.getWidth() / 2;
    drawField("Next Block: ", 2, xMid);

    for (int row = 0; row < 2; ++row) {
      for (int col = 0; col < 3; ++col) {
        window.fillRectangleWithBorder(xMid + NEXT_BLOCK_START + col * sideLength, 
          PADDING + FIELD_HEIGHT + row * sideLength, sideLength, 
          sideLength, Xwindow::White, BORDER_WIDTH);
      }
    }

    if (state.nextBlock == nullptr) {
      return;
    }

    Point bottomLeft = state.nextBlock->getBottomLeft();
    for (Point p : state.nextBlock->pointsOnBoard()) {
      int row = 1 - (p.y - bottomLeft.y);
      int col = p.x - bottomLeft.x;
      window.fillRectangleWithBorder(xMid + NEXT_BLOCK_START + col * sideLength, 
          PADDING + FIELD_HEIGHT + row * sideLength, sideLength, 
          sideLength, tileToColour[state.nextBlock->getType()], BORDER_WIDTH);
    }
  }
}

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

void XDisplay::drawFields(const QuadrisState& state, bool redraw) {
  //if (redraw) {
  if (redraw || state.highScore != lastState.highScore) {
    drawHighScore(state.highScore);
  }
  // if (redraw) {
  if (redraw || state.gameState.score != lastState.gameState.score) {
    drawScore(state.gameState.score);
  }
  // if (redraw) {
  if (redraw || state.gameState.currentLevel != lastState.gameState.currentLevel) {
    drawCurrentLevel(state.gameState.currentLevel);
  }
}

void XDisplay::drawHighScore(int highScore) {
  cout << "Drawing high score " + to_string(highScore) << endl;
  drawField("High Score: " + to_string(highScore), 1, xStart);
}

void XDisplay::drawCurrentLevel(int currentLevel) {
  cout << "Drawing current level " + to_string(currentLevel) << endl;
  drawField("Current Level: " + to_string(currentLevel), 2, xStart);
}

void XDisplay::drawScore(int score) {
  cout << "Drawing score " + to_string(score) << endl;
  drawField("Score: " + to_string(score), 3, xStart);
}

void XDisplay::drawField(string text, int row, int xOffset) {
  // TODO: Remove before handing in
  if (row >= NO_FIELDS) {
    cout << "YOU FUCKED UP NO_FIELDS: " << row << endl;
  }
  cout << "Drawing string " + text << endl;

  // Covering up old text
  window.fillRectangle(xOffset, PADDING + (PADDING + FIELD_HEIGHT) * row, window.getWidth() - 2 * PADDING, FIELD_HEIGHT, Xwindow::White);
  
  // Rer
  window.drawString(xOffset, (PADDING + FIELD_HEIGHT) * (row + 1), text);
}
