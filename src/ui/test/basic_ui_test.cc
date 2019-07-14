#include <memory>
#include <unistd.h>
#include <iostream>
#include "display.h"

using namespace std;

main()
{
  XDisplay d;
  while (1) {
    d.notify();
    std::cout << "What" << std::endl;
    sleep(1);
  }

  // // Open a display.
  // Display *d = XOpenDisplay(0);

  // if ( d )
  //   {
  //     // Create the window
  //     Window w = XCreateWindow(d, DefaultRootWindow(d), 0, 0, 200,
	// 		       100, 0, CopyFromParent, CopyFromParent,
	// 		       CopyFromParent, 0, 0);

  //     // Show the window
  //     XMapWindow(d, w);
  //     XFlush(d);

  //     // Sleep long enough to see the window.
  //     sleep(10);
  //   }

  return 0;
}

unique_ptr<Quadris> mockQuadris() {
    return make_unique<Quadris>(mockGameConfig());
}

GameConfig mockGameConfig() {
    return GameConfig{};
}