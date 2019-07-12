#ifndef INTERFACES_BLOCKS_LBLOCK_H
#define INTERFACES_BLOCKS_LBLOCK_H

#include <memory>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class LBlock : public UnplacedBlock {
  public:
  	LBlock(int score, Point bottomLeft);
};

#endif