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
    cout << "UI HISHISASHSIHSSASIH" << endl;
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
  mtx.lock();

  if (game.expired()) {
    cout << "Quadris pointer expired" << endl;
    return;
  }

  QuadrisState state = game.lock()->getState();
  drawFields(state, redraw);
  drawBoard(state.gameState, redraw);
  lastState = state;

  mtx.unlock();
}

void XDisplay::drawBoard(const GameState& state, bool redraw) {
  int noRows = state.board.size();
  int noCols = state.board[0].size();
  int width = window.getWidth() * 1.0 / noCols;
  int start = NO_FIELDS * (PADDING + FIELD_HEIGHT) + START;
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
  drawField("High Score: " + to_string(highScore), 0);
}

void XDisplay::drawCurrentLevel(int currentLevel) {
  cout << "Drawing current level " + to_string(currentLevel) << endl;
  drawField("Current Level: " + to_string(currentLevel), 1);
}

void XDisplay::drawScore(int score) {
  cout << "Drawing score " + to_string(score) << endl;
  drawField("Score: " + to_string(score), 2);
}

void XDisplay::drawField(string text, int row) {
  // TODO: Remove before handing in
  if (row >= NO_FIELDS) {
    cout << "YOU FUCKED UP NO_FIELDS: " << row << endl;
  }
  cout << "Drawing string " + text << endl;
  window.fillRectangle(PADDING, START + (PADDING + FIELD_HEIGHT)* row, window.getWidth() - 2 * PADDING, FIELD_HEIGHT, 0);
  window.drawString(PADDING, START + (PADDING + FIELD_HEIGHT) * row, text);
}
