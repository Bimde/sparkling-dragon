#include <vector>

#include "src/interfaces/blocks/sBlock.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

namespace {
	const char sBlockType = 'S';
	const std::vector<Point> sBlockOffsets = 
		{{0,0}, {1,0}, {1,1}, {2,1}};
}

SBlock::SBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, sBlockType, bottomLeft, sBlockOffsets} {};