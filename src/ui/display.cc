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

XDisplay::XDisplay() : window{512, 512 / 2 * 3} {}

XDisplay::~XDisplay() {}

void XDisplay::notify() {
  std::cout << "Hello :)" << std::endl;
  updateDisplay();
}

void XDisplay::updateDisplay() {
  window.drawString(15, y++, "Update");
}

// void XDisplay::updateDisplay(GameState gs) {

// }