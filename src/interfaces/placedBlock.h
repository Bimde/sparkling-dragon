#ifndef INTERFACES_PLACED_BLOCK_H
#define INTERFACES_PLACED_BLOCK_H

#include "enums.h"

class PlacedBlock {
    int count;
    int score;
    BlockType type;
  public:
    PlacedBlock(int, int, BlockType);
    int getScore() const;
    int getCount() const;
    void decrementCount();
    BlockType getType() const;
};
#endif // INTERFACES_PLACED_BLOCK_H