#include <vector>

#include "tBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char tBlockType = 't';
	const std::vector<std::pair<int, int>> tBlockOffsets = 
		{{1,0}, {0,1}, {1,1}, {2,1}};
}

TBlock::TBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, tBlockType, bottomLeft, tBlockOffsets} {};