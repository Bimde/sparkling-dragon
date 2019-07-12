#include <vector>

#include "src/interfaces/blocks/tBlock.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

namespace {
	const char tBlockType = 't';
	const std::vector<Point> tBlockOffsets = {{1,0}, {0,1}, {1,1}, {2,1}};
}

TBlock::TBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, tBlockType, bottomLeft, tBlockOffsets} {};