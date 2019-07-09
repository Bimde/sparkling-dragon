#ifndef INTERFACES_BLOCKS_SBLOCK_H
#define INTERFACES_BLOCKS_SBLOCK_H

#include <memory>

#include "unplacedBlock.h"
#include "point.h"

class SBlock : public UnplacedBlock {
  public:
  	SBlock(int score, Point bottomLeft);
};

#endif