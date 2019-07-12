#ifndef INTERFACES_BLOCKS_SBLOCK_H
#define INTERFACES_BLOCKS_SBLOCK_H

#include <memory>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class StarBlock : public UnplacedBlock {
  public:
  	StarBlock(Point bottomLeft);
};

#endif