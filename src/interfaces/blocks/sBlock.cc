#include <vector>

#include "sBlock.h"
#include "interfaces/unplacedBlock.h"
#include "interfaces/point.h"

namespace {
	const char sBlockType = 's';
	const std::vector<Point> sBlockOffsets = 
		{{0,0}, {1,0}, {1,1}, {2,1}};
}

SBlock::SBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, sBlockType, bottomLeft, sBlockOffsets} {};