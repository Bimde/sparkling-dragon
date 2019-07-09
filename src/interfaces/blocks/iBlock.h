#ifndef INTERFACES_BLOCKS_IBLOCK_H
#define INTERFACES_BLOCKS_IBLOCK_H

#include <memory>

#include "unplacedBlock.h"
#include "point.h"

class IBlock : public UnplacedBlock {
  public:
  	IBlock(int score, Point bottomLeft);
};

#endif