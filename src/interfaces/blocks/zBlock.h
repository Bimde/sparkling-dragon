#ifndef INTERFACES_BLOCKS_ZBLOCK_H
#define INTERFACES_BLOCKS_ZBLOCK_H

#include <memory>

#include "unplacedBlock.h"
#include "point.h"

class ZBlock : public UnplacedBlock {
  public:
  	ZBlock(int score, Point bottomLeft);
};

#endif