#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

#include <utility>

#include "board.h"
#include "levelInterface.h"
#include "levelFactory.h"
#include "gameState.h"

class Game {
	int score;
	Board board;

	std::unique_ptr<UnplacedBlock> nextBlock;

	std::unique_ptr<LevelFactory> levelFactory;
	std::shared_ptr<LevelInterface> currentLevel;
	std::shared_ptr<LevelInterface> nextLevel;
  public:
  	Game(std::unique_ptr<LevelFactory> levelFactory, int startingLevel);

  	bool moveCurrentBlockDown();
  	bool moveCurrentBlockLeft();
  	bool moveCurrentBlockRight();
  	bool dropCurrentBlock();

  	void setNextLevel(int level);

  	void reset();

  	GameState getState();
  	int score();
};

#endif