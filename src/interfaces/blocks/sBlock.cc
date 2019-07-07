#include <vector>

#include "sBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char sBlockType = 's';
	const std::vector<std::pair<int, int>> sBlockOffsets = 
		{{0,0}, {1,0}, {1,1}, {2,1}};
}

SBlock::SBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, sBlockType, bottomLeft, sBlockOffsets} {};