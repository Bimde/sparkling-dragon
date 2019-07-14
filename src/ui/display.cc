#include <X11/Xlib.h>
#include <iostream>
#include <string>
#include <unistd.h>

#include "display.h"
#include "../interfaces/gameState.h"
#include "window.h"

// XDisplay::XDisplay(std::weak_ptr<Game> game): game{game} {
//   Xwindow window{512, 512 / 2 * 3};
// }

XDisplay::XDisplay() : 
  window{512, 512 / 2 * 3}, 
  tileToColour{
    {'I', Xwindow::Black},
    {'J', Xwindow::Red},
    {'L', Xwindow::Green},
    {'O', Xwindow::Blue},
    {'S', Xwindow::Black},
    {'Z', Xwindow::Red},
    {'T', Xwindow::Green}
  } {}

XDisplay::~XDisplay() {}

void XDisplay::notify() {
  std::cout << "Hello :)" << std::endl;
  updateDisplay();
}

void XDisplay::updateDisplay() {
  //window.drawString(15, y++, "Update");
  //window.fillRectangle(y, y, 50, 50, y % 5);

  int noRows = 10;
  int noCols = 10;
  int width = window.getWidth() * 1.0 / noCols;
  int height = window.getHeight() * 1.0 / noRows;
  for (int i = 0; i < noRows; i++) {
    for (int j = 0; j < noCols; j++) {
      window.fillRectangle(j*width, i*height, width, height, (i + j) % 5);
    }
  }
}

// void XDisplay::updateDisplay(GameState gs) {

// }