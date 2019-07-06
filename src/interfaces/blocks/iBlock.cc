#include <vector>

#include "iBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char iBlockType = 'i';
	const std::vector<std::pair<int, int>> iBlockOffsets = 
		{{0,0}, {1,0}, {2,0}, {3,0}};
}

IBlock::IBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, iBlockType, bottomLeft, iBlockOffsets} {};