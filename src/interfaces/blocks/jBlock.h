#ifndef INTERFACES_BLOCKS_JBLOCK_H
#define INTERFACES_BLOCKS_JBLOCK_H

#include <memory>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class JBlock : public UnplacedBlock {
  public:
  	JBlock(int score, Point bottomLeft);
};

#endif