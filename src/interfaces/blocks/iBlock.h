#ifndef INTERFACES_BLOCKS_IBLOCK_H
#define INTERFACES_BLOCKS_IBLOCK_H

#include "unplacedBlock.h"

class IBlock : public UnplacedBlock {
  public:
  	IBlock(int score, std::pair<int, int> bottomLeft);

  	static IBlock create(int score, std::pair<int, int> bottomLeft);
};

#endif