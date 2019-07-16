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
    XDisplay(Quadris* game);
    virtual ~XDisplay();
    virtual void notify();
    
  private:
    static const int WINDOW_HEIGHT = 800;
    static const int WINDOW_WIDTH = 600;
    static const int PADDING = 10;
    static const int FIELD_HEIGHT = 10;
    static const int CHAR_WIDTH = 10;
    static const int NO_FIELDS = 5;
    static const int BORDER_WIDTH = 1;
    static const int NEXT_BLOCK_TEXT_START = 0;
    static const int NEXT_BLOCK_START = 80;
    static const int GAME_OVER_COLOUR = XWindow::Pink;
    static const char EMPTY = ' ';

    XWindow window;
    std::unordered_map<char, int> tileToColour;
    Quadris* game;
    QuadrisState lastState;

    int xStart;
    int yStart;
    int sideLength;

    void calculateDimensions(const GameState&);
    
    void updateDisplay(bool);
    void drawGameOver(const GameState&, bool);
    void drawBoard(const GameState&, bool);
    void drawNextBlock(const GameState&, bool);

    void drawFields(const QuadrisState&, bool);
    void drawHighScore(int);
    void drawScore(int);
    void drawCurrentLevel(int);

    void drawField(std::string, int, int);
};

#endif