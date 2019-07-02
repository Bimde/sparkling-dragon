#ifndef INTERFACES_BLOCKS_LBLOCK_H
#define INTERFACES_BLOCKS_LBLOCK_H

#include <memory>

#include "unplacedBlock.h"

class LBlock : public UnplacedBlock {
  public:
  	LBlock(int score, std::pair<int, int> bottomLeft);

  	static std::unique_ptr<LBlock> create(int score, 
  										  std::pair<int, int> bottomLeft);
};

#endif