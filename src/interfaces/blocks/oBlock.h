#ifndef INTERFACES_BLOCKS_OBLOCK_H
#define INTERFACES_BLOCKS_OBLOCK_H

#include "unplacedBlock.h"

class OBlock : public UnplacedBlock {
  public:
  	OBlock(int score, std::pair<int, int> bottomLeft);

  	static OBlock create(int score, std::pair<int, int> bottomLeft);
};

#endif