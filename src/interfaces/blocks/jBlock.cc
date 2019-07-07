#include <vector>

#include "jBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char jBlockType = 'j';
	const std::vector<std::pair<int, int>> jBlockOffsets = 
		{{0,0}, {1,0}, {2,0}, {0,1}};
}

JBlock::JBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, jBlockType, bottomLeft, jBlockOffsets} {};