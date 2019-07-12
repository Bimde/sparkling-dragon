#ifndef INTERFACES_BLOCKS_TBLOCK_H
#define INTERFACES_BLOCKS_TBLOCK_H

#include <memory>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class TBlock : public UnplacedBlock {
  public:
  	TBlock(int score, Point bottomLeft);
};

#endif