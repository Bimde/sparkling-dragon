#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <memory>
#include <unordered_map>
#include <string>

#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "window.h"
#include "src/interfaces/observer.h"

class XDisplay : Observer {
  public:
    XDisplay(std::weak_ptr<Quadris> game);
    //XDisplay();
    virtual ~XDisplay();
    virtual void notify();
  private:
    const int PADDING = 10;
    const int FIELD_HEIGHT = 50;
    const int NO_FIELDS = 3;
    Xwindow window;
    std::unordered_map<char, int> tileToColour;
    std::weak_ptr<Quadris> game;
    QuadrisState lastState;
    
    void updateDisplay(bool);
    void drawBoard(const GameState&, bool);

    void drawFields(const QuadrisState&, bool);
    void drawHighScore(int);
    void drawScore(int);
    void drawCurrentLevel(int);

    void drawField(std::string, int);
};

#endif