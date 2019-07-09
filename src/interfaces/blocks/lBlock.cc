#include <vector>

#include "lBlock.h"
#include "interfaces/unplacedBlock.h"
#inclide "interfaces/point.h"

namespace {
	const char lBlockType = 'l';
	const std::vector<Point> lBlockOffsets = {{0,0}, {1,0}, {2,0}, {2,1}};
}

LBlock::LBlock(int score, Point bottomLeft) : 
	UnplacedBlock{score, lBlockType, bottomLeft, lBlockOffsets} {};