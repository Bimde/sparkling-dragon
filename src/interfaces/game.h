#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

#include <memory>
#include <utility>

#include "src/interfaces/board.h"
#include "src/interfaces/levelInterface.h"
#include "src/interfaces/levelFactory.h"
#include "src/interfaces/gameState.h"
#include "src/interfaces/hintGenerator.h"

const int defaultStartLevel = 0;

class GameConfig {
    int startLevel_;
    LevelConfig lvlcfg_;
  public:
    GameConfig() : startLevel_{defaultStartLevel} {}

    int startLevel() { return startLevel_; }
    void setStartLevel(int level) { startLevel_ = level; }

    LevelConfig getLevelConfig() { return lvlcfg_; } 
    void setSeed(int seed) { lvlcfg_.setSeed(seed); }
    void setFilename(std::string filename) { lvlcfg_.setFilename(filename); }
};

class Game {
  std::unique_ptr<LevelFactory> levelFactory_;
  std::shared_ptr<HintGenerator> hinter_;

	int score;
  bool showHint;

	int nextLevel;

  std::shared_ptr<LevelInterface> currentLevel;

	std::unique_ptr<Board> board;
	std::unique_ptr<UnplacedBlock> nextBlock;

  void completeTurn();
  
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

  	GameState getState();

  	int getScore();

    bool isGameOver();

    static std::unique_ptr<Game> create(GameConfig cfg);
};

#endif