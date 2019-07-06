#include <vector>

#include "zBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char zBlockType = 'z';
	const std::vector<std::pair<int, int>> zBlockOffsets = 
		{{0,0}, {1,0}, {1,1}, {2,1}};
}

ZBlock::ZBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, zBlockType, bottomLeft, zBlockOffsets} {};