#ifndef INTERFACES_BOARD_H
#define INTERFACES_BOARD_H

class Board {
	  UnplacedBlock currentBlock;
	  std::vector<std::vector<std::shared_ptr<PlacedBlock>>> board;
  public:
  	Board();

  	void setCurrent(UnplacedBlock);

  	bool moveCurrentDown();
  	bool moveCurrentLeft();
  	bool moveCurrentRight();
  	bool dropCurrent();

  	void placeCurrent();

  	// Checks if the current block overlaps other already placed blocks
  	bool isCurrentOverlapping();
  	
  	void numberOfFullRows();
  	std::vector<std::shared_ptr<PlacedBlock>> 
  		destroyFullRowsAndGetDestroyedPlacedBlocks();
};

#endif