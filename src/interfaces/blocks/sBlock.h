#ifndef INTERFACES_BLOCKS_SBLOCK_H
#define INTERFACES_BLOCKS_SBLOCK_H

#include "unplacedBlock.h"

class SBlock : public UnplacedBlock {
  public:
  	SBlock(int score, std::pair<int, int> bottomLeft);

  	static SBlock create(int score, std::pair<int, int> bottomLeft);
};

#endif