#ifndef INTERFACES_BLOCKS_TBLOCK_H
#define INTERFACES_BLOCKS_TBLOCK_H

#include "unplacedBlock.h"

class TBlock : public UnplacedBlock {
  public:
  	TBlock(int score, std::pair<int, int> bottomLeft);

  	static TBlock create(int score, std::pair<int, int> bottomLeft);
};

#endif