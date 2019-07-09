#ifndef INTERFACES_BLOCKS_OBLOCK_H
#define INTERFACES_BLOCKS_OBLOCK_H

#include <memory>

#include "unplacedBlock.h"
#include "point.h"

class OBlock : public UnplacedBlock {
  public:
  	OBlock(int score, Point bottomLeft);
};

#endif