#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <memory>

#include "game.h"
#include "observer.h"

class Display : Observer {
  public:
    Display(std::weak_ptr<Game> game);
    virtual void notify();
  private:
    void updateDisplay(GameState);
};

#endif