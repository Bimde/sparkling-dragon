#ifndef INTERFACES_BOARD_H
#define INTERFACES_BOARD_H

#include <utility>


class Board {
	  std::unique_ptr<UnplacedBlock> currentBlock;
	  std::vector<std::vector<std::shared_ptr<PlacedBlock>>> board;
  public:
  	Board();

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
};

#endif