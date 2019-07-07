#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

#include <utility>

#include "board.h"
#include "levelInterface.h"
#include "levelFactory.h"
#include "gameState.h"

class Game {
  std::unique_ptr<LevelFactory> levelFactory;
  std::shared_ptr<HintGenerator> hinter;

	int score;
	int nextLevel;
  bool showHint;

	std::unique_ptr<Board> board;
	std::unique_ptr<UnplacedBlock> nextBlock;
  std::shared_ptr<LevelInterface> currentLevel;
  
  public:
  	Game(std::unique_ptr<LevelFactory> levelFactory, 
         std::shared_ptr<HintGenerator> hinter, int startingLevel);

  	bool moveCurrentBlockDown();
  	bool moveCurrentBlockLeft();
  	bool moveCurrentBlockRight();
  	bool dropCurrentBlock();
    bool rotateCurrentBlockLeft();
    bool rotateCurrentBlockRight();

  	void increaseLevel();
  	void decreaseLevel();
    // Sets the input as a file for certain levels
    void useFileForLevel(std::string filename);
    // Makes certain levels random.
    void randomizeLevels();

  	void enableHint();
  	void disableHint();

    void doLevelActionAfterMove();

  	void reset();
  	GameState getState();

  	int score() { return score };
};

#endif