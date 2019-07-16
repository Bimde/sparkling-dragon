#ifndef UI_DISPLAY_H
#define UI_DISPLAY_H

#include <memory>
#include <unordered_map>
#include <string>

#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "window.h"
#include "src/interfaces/observer.h"

class XDisplay : public Observer {
  public:
    XDisplay(std::weak_ptr<Quadris> game);
    virtual ~XDisplay();
    virtual void notify();
  private:
    const int WINDOW_HEIGHT = 800;
    const int WINDOW_WIDTH = 600;
    const int PADDING = 10;
    const int FIELD_HEIGHT = 10;
    const int NO_FIELDS = 5;
    const int BORDER_WIDTH = 1;
    const int NEXT_BLOCK_START = 80;

    Xwindow window;
    std::unordered_map<char, int> tileToColour;
    std::weak_ptr<Quadris> game;
    QuadrisState lastState;

    int xStart;
    int yStart;
    int sideLength;

    void calculateDimensions(const GameState&);
    
    void updateDisplay(bool);
    void drawBoard(const GameState&, bool);
    void drawNextBlock(const GameState&, bool);

    void drawFields(const QuadrisState&, bool);
    void drawHighScore(int);
    void drawScore(int);
    void drawCurrentLevel(int);

    void drawField(std::string, int, int);
};

#endif