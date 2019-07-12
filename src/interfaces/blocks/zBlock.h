#ifndef INTERFACES_BLOCKS_ZBLOCK_H
#define INTERFACES_BLOCKS_ZBLOCK_H

#include <memory>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class ZBlock : public UnplacedBlock {
  public:
  	ZBlock(int score, Point bottomLeft);
};

#endif