#include <vector>

#include "jBlock.h"
#include "interfaces/unplacedBlock.h"
#include "interfaces/point.h"

namespace {
	const char jBlockType = 'j';
	const std::vector<Point> jBlockOffsets = {{0,0}, {1,0}, {2,0}, {0,1}};
}

JBlock::JBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, jBlockType, bottomLeft, jBlockOffsets} {};