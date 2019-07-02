#ifndef INTERFACES_PLACED_BLOCK_H
#define INTERFACES_PLACED_BLOCK_H

#include "block.h"

class PlacedBlock : public Block {
	int count;
  public:
	PlacedBlock(int score, int type, int count);
	~PlacedBlock();

	void decrementCount();
	// Checks if the block is fully destroyed
	bool isDestroyed();
};

#endif