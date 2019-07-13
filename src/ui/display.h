#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <memory>
#include <unordered_map>

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
    std::unordered_map<char, int> tileToColour;
    
    // std::weak_ptr<Game> game;
    // void updateDisplay(GameState);
    void updateDisplay();
};

#endif