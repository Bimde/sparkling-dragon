#include <vector>

#include "src/interfaces/blocks/zBlock.h"

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

namespace {
	const char zBlockType = 'Z';
	const std::vector<Point> zBlockOffsets = {{1,0}, {2,0}, {0,1}, {1,1}};
}

ZBlock::ZBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, zBlockType, bottomLeft, zBlockOffsets} {};