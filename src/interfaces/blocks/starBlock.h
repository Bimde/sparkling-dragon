#ifndef INTERFACES_BLOCKS_SBLOCK_H
#define INTERFACES_BLOCKS_SBLOCK_H

#include <memory>

#include "unplacedBlock.h"

class StarBlock : public UnplacedBlock {
  public:
  	StarBlock(std::pair<int, int> bottomLeft);

  	static std::unique_ptr<StarBlock> create(std::pair<int, int> bottomLeft);
};

#endif