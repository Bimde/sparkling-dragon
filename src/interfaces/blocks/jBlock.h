#ifndef INTERFACES_BLOCKS_JBLOCK_H
#define INTERFACES_BLOCKS_JBLOCK_H

#include <memory>

#include "unplacedBlock.h"

class JBlock : public UnplacedBlock {
  public:
  	JBlock(int score, std::pair<int, int> bottomLeft);

  	static std::unique_ptr<JBlock> create(int score, 
  										  std::pair<int, int> bottomLeft);
};

#endif