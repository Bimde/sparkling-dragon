#ifndef UI_TEST_MOCKS_H
#define UI_TEST_MOCKS_H
#include <memory>
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "src/interfaces/gameState.h"

class MockQuadris : public Quadris {
    QuadrisState state;
  public:
    MockQuadris(QuadrisState);
    QuadrisState getState() override;
};

namespace UIMocks {
  QuadrisState createQuadrisState();
  QuadrisState createQuadrisState(GameState);
  GameState createGameState();
  GameState createGameState(std::vector<std::vector<char>>);
  std::vector<std::vector<char>> createBoard();
}

#endif