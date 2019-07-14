#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <unistd.h>

#include "display.h"
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "window.h"

// XDisplay::XDisplay(std::weak_ptr<Game> game): game{game} {
//   Xwindow window{512, 512 / 2 * 3};
// }

using namespace std;

XDisplay::XDisplay(std::weak_ptr<Quadris> game) : 
  window{512, 512 / 2 * 3},
  tileToColour{
    {'I', Xwindow::Black},
    {'J', Xwindow::Red},
    {'L', Xwindow::Green},
    {'O', Xwindow::Blue},
    {'S', Xwindow::Black},
    {'Z', Xwindow::Red},
    {'T', Xwindow::Green},
    {' ', Xwindow::White}
  }, 
  game{game},
  lastState{game.lock()->getState()}
  {
    updateDisplay(true);
  }

XDisplay::~XDisplay() {}

void XDisplay::notify() {
  std::cout << "display notified" << std::endl;
  updateDisplay(false);
}

void XDisplay::updateDisplay(bool redraw) {
  //window.drawString(15, y++, "Update");
  //window.fillRectangle(y, y, 50, 50, y % 5);

  if (game.expired()) {
    cerr << "Quadris pointer expired" << endl;
    return;
  }

  QuadrisState state = game.lock()->getState();
  drawFields(state, redraw);
  drawBoard(state.gameState, redraw);

  // TODO why can't I do this
  lastState = state;
}

void XDisplay::drawBoard(const GameState& state, bool redraw) {
  int noRows = state.board.size();
  int noCols = state.board[0].size();
  int width = window.getWidth() * 1.0 / noCols;
  int start = NO_FIELDS * (PADDING + FIELD_HEIGHT) + PADDING;
  int height = (window.getHeight() * 1.0 - start) / noRows;
  for (int i = 0; i < noRows; i++) {
    for (int j = 0; j < noCols; j++) {
      if (redraw || state.board[i][j] != lastState.gameState.board[i][j]) {
        window.fillRectangle(j * width, start + i * height, width, height, tileToColour[state.board[i][j]]);
      }
    }
  }
}

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
  drawField("High Score: " + highScore, 0);
}

void XDisplay::drawCurrentLevel(int currentLevel) {
  drawField("Current Level: " + currentLevel, 1);
}

void XDisplay::drawScore(int score) {
  drawField("Score: " + score, 2);
}

void XDisplay::drawField(string text, int row) {
  // TODO: Remove before handing in
  if (row >= NO_FIELDS) {
    cerr << "YOU FUCKED UP NO_FIELDS" << endl;
  }
  window.fillRectangle(PADDING, 0, window.getWidth() - 2 * PADDING, FIELD_HEIGHT, 0);
  window.drawString(PADDING, PADDING + PADDING * row + FIELD_HEIGHT * row, text);
}
