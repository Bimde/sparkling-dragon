#include <vector>

#include "src/interfaces/blocks/iBlock.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

namespace {
	const char iBlockType = 'I';
	const std::vector<Point> iBlockOffsets = {{0,0}, {1,0}, {2,0}, {3,0}};
}

IBlock::IBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, iBlockType, bottomLeft, iBlockOffsets} {};