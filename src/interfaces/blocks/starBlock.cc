#include <vector>

#include "starBlock.h"
#include "interfaces/unplacedBlock.h"

namespace {
	const int starBlockPoints = 0;
	const char starBlockType = '*';
	const std::vector<std::pair<int, int>> starBlockOffsets = 
		{{0,0}};
}

StarBlock::StarBlock(std::pair<int, int> bottomLeft) : 
	UnplacedBlock{starBlockPoints, starBlockType, bottomLeft, starBlockOffsets} {};