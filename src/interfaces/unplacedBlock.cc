#include <vector>
#include <utility>
#include <climits>

#include "unplacedBlock.h"
#include "block.h"

UnplacedBlock::UnplacedBlock(
	int score, char type, Point bottomLeft, std::vector<Point> offsets) :
	Block{score, type}, bottomLeft{bottomLeft}, offsets{std::move(offsets)} {}

UnplacedBlock::~UnplacedBlock() {}

void UnplacedBlock::moveDown() {
	--bottomLeft.second;
}
void UnplacedBlock::moveRight() {
	++bottomLeft.first;
}

void UnplacedBlock::moveLeft() {
	--bottomLeft.first;
}

void UnplacedBlock::rotateLeft() {
	if (offsets.size() == 0) {
		return;
	}

	std::vector<Point> newOffsets;
	newOffsets.reserve(offsets.size());

	int smallestX = INT_MAX;
	int smallestY = INT_MAX;
	for (const auto& coord : offsets) {
		// Rotate each coordinate vector 90 degrees clockwise
		Point rotatedCoord{coord.y, -coord.x};
		newOffsets.emplace_back(rotatedCoord);

		smallestX = smallestX < rotatedCoord.x ? 
			smallestX : rotatedCoord.x;
		smallestY = smallestY < rotatedCoord.y ? 
			smallestY : rotatedCoord.y;
	}

	// Shift all coordinates so they are in the first quadrant
	// and as close to the left corner as possible
	for (auto& newCoord : newOffsets) {
		newCoord.x -= smallestX;
		newCoord.y -= smallestY;
	}

	offsets.swap(newOffsets);
}

void UnplacedBlock::rotateRight() {
	rotateLeft();
	rotateLeft();
	rotateLeft();
}