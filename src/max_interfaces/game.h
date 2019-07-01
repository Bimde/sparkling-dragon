#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

#include "levelInterface.h"
#include "levelFactory.h"

// Maybe can improve this using pImpl tbh LOL
struct GameState {
	const int score;
	const std::vector<std::vector<char>> board;

	// Other fields
};

class Game {
	int score;

	Board board;
	UnplacedBlock nextBlock;

	std::unique_ptr<LevelFactory> levelFactory;

	std::shared_ptr<LevelInterface> currentLevel;
	std::shared_ptr<LevelInterface> nextLevel;
  public:
  	Game(std::unique_ptr<LevelFactory> levelFactory);

  	GameState getState();

  	void setNextLevel(int level);
  	void reset();

  	// All moves
};

#endif