#ifndef INTERFACES_BOARD_H
#define INTERFACES_BOARD_H

#include <vector>
#include <memory>

class HintGenerator;
class UnplacedBlock;
class PlacedBlock;

class Board {
    bool showHint;

	  std::unique_ptr<UnplacedBlock> currentBlock;
	  std::vector<std::vector<std::shared_ptr<PlacedBlock>>> board;

    std::shared_ptr<HintGenerator> hinter;
  public:
  	Board(std::shared_ptr<HintGenerator> hinter);

  	void setCurrent(std::unique_ptr<UnplacedBlock>);

  	bool moveCurrentDown();
  	bool moveCurrentLeft();
  	bool moveCurrentRight();
  	bool dropCurrent();

    void numberOfFullRows();

  	// Checks if the current block overlaps other already placed blocks
  	bool isCurrentOverlapping();
  	
    // TODO break this up (or make it cleaner)
  	std::vector<std::shared_ptr<PlacedBlock>> 
  		destroyFullRowsAndGetDestroyedPlacedBlocks();

    void reset();

    // Generates the state of the board with or without the hint (depending)
    // on the hint flags value
    std::vector<std::vector<char>> getState();
};

#endif