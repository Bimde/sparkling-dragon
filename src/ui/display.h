#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <memory>

// #include "../interfaces/game.h"
#include "../interfaces/gameState.h"
#include "window.h"
#include "observer.h"

// class Game;

class XDisplay : Observer {
  public:
    // XDisplay(std::weak_ptr<Game> game);
    XDisplay();
    virtual ~XDisplay();
    virtual void notify();
  private:
    int y = 15;
    Xwindow window;
    // std::weak_ptr<Game> game;
    // void updateDisplay(GameState);
    void updateDisplay();
};

#endif