#include <vector>

#include "oBlock.h"
#include "interfaces/unplacedBlock.h"
#include "interfaces/point.h"

namespace {
	const char oBlockType = 'o';
	const std::vector<Point> oBlockOffsets = {{0,0}, {1,0}, {0,1}, {1,1}};
}

OBlock::OBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, oBlockType, bottomLeft, oBlockOffsets} {};