#include <memory>
#include "src/interfaces/quadris.h"
#include "src/interfaces/quadrisState.h"
#include "src/interfaces/game.h"
#include "src/interfaces/gameState.h"
#include "mocks.h"

namespace {
  const int level = 0;
  const int highScore = 100;
  const int score = 42;
  const char * curCommand = "WOW";
}

MockQuadris::MockQuadris(QuadrisState state) : Quadris{GameConfig{}}, state{state} {
  std::cout << "Hi" << std::endl;
}

QuadrisState MockQuadris::getState() {
  return state;
}

namespace UIMocks {
QuadrisState createQuadrisState() {
  return QuadrisState{highScore, curCommand, createGameState()};
}


QuadrisState createQuadrisState(GameState gameState) {
  std::cout << "createQuadState" << std::endl;
  return QuadrisState{highScore, curCommand, gameState};
}

GameState createGameState() {
  return GameState{level, score, createBoard()};
}

GameState createGameState(std::vector<std::vector<char>> board) {
  std::cout << "createGameState" << std::endl;
  return GameState{level, score, board};
}

std::vector<std::vector<char>> createBoard() {
  return std::vector<std::vector<char>>{};
}
}  // namespace UIMocks
