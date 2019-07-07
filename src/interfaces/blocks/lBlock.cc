#include <vector>

#include "lBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const char lBlockType = 'l';
	const std::vector<std::pair<int, int>> jBlockOffsets = 
		{{0,0}, {1,0}, {2,0}, {2,1}};
}

LBlock::LBlock(int score, std::pair<int, int> bottomLeft) : 
	UnplacedBlock{score, lBlockType, bottomLeft, lBlockOffsets} {};