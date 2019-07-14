#include <vector>

#include "src/interfaces/blocks/oBlock.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

namespace {
	const char oBlockType = 'O';
	const std::vector<Point> oBlockOffsets = {{0,0}, {1,0}, {0,1}, {1,1}};
}

OBlock::OBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, oBlockType, bottomLeft, oBlockOffsets} {};