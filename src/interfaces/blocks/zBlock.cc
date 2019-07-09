#include <vector>

#include "zBlock.h"
#include "interfaces/unplacedBlock.h"
#include "interfaces/point.h"

namespace {
	const char zBlockType = 'z';
	const std::vector<Point> zBlockOffsets = {{0,0}, {1,0}, {1,1}, {2,1}};
}

ZBlock::ZBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, zBlockType, bottomLeft, zBlockOffsets} {};