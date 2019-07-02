#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

#include <utility>

#include "board.h"
#include "levelInterface.h"
#include "levelFactory.h"
#include "gameState.h"

class Game {
	int score;
	int level;
  bool showHint;

	std::unique_ptr<Board> board;

	std::unique_ptr<UnplacedBlock> nextBlock;

	std::unique_ptr<LevelFactory> levelFactory;
	std::shared_ptr<LevelInterface> currentLevel;

  std::shared_ptr<HintGenerator> hinter;
  
  public:
  	Game(std::unique_ptr<LevelFactory> levelFactory, 
         std::shared_ptr<HintGenerator> hinter, int startingLevel);

  	bool moveCurrentBlockDown();
  	bool moveCurrentBlockLeft();
  	bool moveCurrentBlockRight();
  	bool dropCurrentBlock();

  	void increaseLevel();
  	void decreaseLevel();
    // Sets the input as a file for certain levels
    void useFileForLevel(std::string filename);
    // Makes certain levels random.
    void randomizeLevels();

  	void enableHint();
  	void disableHint();

  	void reset();

  	GameState getState();
  	int score();
};

#endif