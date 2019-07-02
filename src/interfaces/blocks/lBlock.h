#ifndef INTERFACES_BLOCKS_LBLOCK_H
#define INTERFACES_BLOCKS_LBLOCK_H

#include "unplacedBlock.h"

class LBlock : public UnplacedBlock {
  public:
  	LBlock(int score, std::pair<int, int> bottomLeft);

  	static LBlock create(int score, std::pair<int, int> bottomLeft);
};

#endif