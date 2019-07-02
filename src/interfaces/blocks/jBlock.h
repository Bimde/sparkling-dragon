#ifndef INTERFACES_BLOCKS_JBLOCK_H
#define INTERFACES_BLOCKS_JBLOCK_H

#include "unplacedBlock.h"

class JBlock : public UnplacedBlock {
  public:
  	JBlock(int score, std::pair<int, int> bottomLeft);

  	static JBlock create(int score, std::pair<int, int> bottomLeft);
};

#endif