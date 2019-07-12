#include <vector>

#include "src/interfaces/blocks/starBlock.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
	const int starBlockPoints = 0;
	const char starBlockType = '*';
	const std::vector<Point> starBlockOffsets = {{0,0}};
}

StarBlock::StarBlock(Point bottomLeft) : 
	UnplacedBlock{starBlockPoints, starBlockType, bottomLeft, starBlockOffsets} {};