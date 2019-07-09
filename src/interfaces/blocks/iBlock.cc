#include <vector>

#include "iBlock.h"
#include "interfaces/unplacedBlock.h"
#include "interfaces/point.h"

namespace {
	const char iBlockType = 'i';
	const std::vector<Point> iBlockOffsets = {{0,0}, {1,0}, {2,0}, {3,0}};
}

IBlock::IBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, iBlockType, bottomLeft, iBlockOffsets} {};