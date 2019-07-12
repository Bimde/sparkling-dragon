#ifndef INTERFACES_PLACED_BLOCK_H
#define INTERFACES_PLACED_BLOCK_H

#include "src/interfaces/block.h"

class PlacedBlock : public Block {
	int count;

  public:
	PlacedBlock(int score, int type, int count) : 
		Block{score, type}, count{count} {}

	void decrementCount() { --count; }

	// Checks if the block is fully destroyed
	bool isDestroyed() { return count <= 0 };
};

#endif