#ifndef INTERFACES_BLOCKS_TBLOCK_H
#define INTERFACES_BLOCKS_TBLOCK_H

#include <memory>

#include "unplacedBlock.h"

class TBlock : public UnplacedBlock {
  public:
  	TBlock(int score, std::pair<int, int> bottomLeft);

  	static std::unique_ptr<TBlock> create(int score, 
  										  std::pair<int, int> bottomLeft);
};

#endif