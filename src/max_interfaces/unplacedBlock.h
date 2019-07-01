#ifndef INTERFACES_UNPLACED_BLOCK_H
#define INTERFACES_UNPLACED_BLOCK_H

#include "block.h"

class UnplacedBlock : public Block {
	std::pair<int, int> bottomLeft;
	std::vector<std::pair<int, int>> offsets;
  public:
  	UnplacedBlock(int score, char type, std::pair<int, int> bottomLeft, 
  		            std::vector<std::pair<int, int>> offsets);
  	~UnplacedBlock();

  	void rotateLeft();
  	void moveDown();
  	void moveRight();
  	void moveLeft();
};

// We might want to either use factory fns for generating the different
// block types or individual base classes.

// We can discuss what is better tmrw. Might be easier to do factory fns
// (e.g. static UnplacedBlock [createS() / createT(), etc..])

#endif