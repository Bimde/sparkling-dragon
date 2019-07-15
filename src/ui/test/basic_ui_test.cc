#include <memory>
#include <unistd.h>
#include <iostream>
#include "src/ui/display.h"
#include "src/interfaces/quadrisState.h"
#include "src/interfaces/gameState.h"
#include "mocks.h"
#include "src/interfaces/quadris.h"
#include "basic_ui_test.h"

using namespace std;

std::vector<std::vector<char>> createBoard();

namespace {
}

// int main()
// {
//   // while (1) {
//   //   display.notify();
//   //   std::cout << "What" << std::endl;
//   //   sleep(1);
//   // }

//   // // Open a display.
//   // Display *d = XOpenDisplay(0);

//   // if ( d )
//   //   {
//   //     // Create the window
//   //     Window w = XCreateWindow(d, DefaultRootWindow(d), 0, 0, 200,
// 	// 		       100, 0, CopyFromParent, CopyFromParent,
// 	// 		       CopyFromParent, 0, 0);

//   //     // Show the window
//   //     XMapWindow(d, w);
//   //     XFlush(d);

//   //     // Sleep long enough to see the window.
//   //     sleep(10);
//   //   }

//   return 0;
// }

std::vector<std::vector<char>> createBoard() {
  return std::vector<std::vector<char>>{
      {'S', 'I', 'L', 'O', 'J',},
      {'I', 'I', 'L', ' ', 'J',},
      {'I', ' ', 'O', 'O', 'J',},
      {'I', 'I', 'L', 'O', ' ',},
      {'S', 'I', 'L', ' ', 'J',}
  };
}

void simpleTest() {
  QuadrisState state = UIMocks::createQuadrisState(UIMocks::createGameState(createBoard()));
  shared_ptr<MockQuadris> quadris = make_shared<MockQuadris>(state);
  XDisplay display{quadris};
  while (1) {
    display.notify();
    std::cout << "What" << std::endl;
    sleep(1);
  }
}

bool BasicUITest::runTests() {
  simpleTest();
  return true;
}
