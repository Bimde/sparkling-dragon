#ifndef INTERFACES_BLOCKS_TBLOCK_H
#define INTERFACES_BLOCKS_TBLOCK_H

#include <memory>

#include "unplacedBlock.h"
#include "point.h"

class TBlock : public UnplacedBlock {
  public:
  	TBlock(int score, Point bottomLeft);
};

#endif