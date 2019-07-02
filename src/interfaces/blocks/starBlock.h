#ifndef INTERFACES_BLOCKS_SBLOCK_H
#define INTERFACES_BLOCKS_SBLOCK_H

#include "unplacedBlock.h"

class StarBlock : public UnplacedBlock {
  public:
  	StarBlock(std::pair<int, int> bottomLeft);

  	static StarBlock create(std::pair<int, int> bottomLeft);
};

#endif