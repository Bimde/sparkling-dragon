#include <vector>

#include "oBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char oBlockType = 'o';
	const std::vector<std::pair<int, int>> jBlockOffsets = 
		{{0,0}, {1,0}, {0,1}, {1,1}};
}

OBlock::OBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, oBlockType, bottomLeft, oBlockOffsets} {};