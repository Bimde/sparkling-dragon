#ifndef INTERFACES_UNPLACED_BLOCK_H
#define INTERFACES_UNPLACED_BLOCK_H

#include <vector>

#include "placedBlock.h"

class UnplacedBlock {
    std::pair<int, int> bottomLeft;
    std::vector<std::pair<int, int>> offsets;
    PlacedBlock block;

  public:
    UnplacedBlock(std::pair<int, int>,std::vector<std::pair<int, int>>, PlacedBlock);
    bool rotateLeft();
    bool moveDown(int);
};

#endif // INTERFACES_UNPLACED_BLOCK_H