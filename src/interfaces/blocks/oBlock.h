#ifndef INTERFACES_BLOCKS_OBLOCK_H
#define INTERFACES_BLOCKS_OBLOCK_H

#include <memory>

#include "unplacedBlock.h"

class OBlock : public UnplacedBlock {
  public:
  	OBlock(int score, std::pair<int, int> bottomLeft);

  	static std::unique_ptr<OBlock> create(int score, 
  										  std::pair<int, int> bottomLeft);
};

#endif