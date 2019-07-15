#include <vector>
#include <utility>
#include <climits>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/block.h"
#include "src/interfaces/point.h"

UnplacedBlock::UnplacedBlock(
	int score, char type, Point bottomLeft, std::vector<Point> offsets) :
	Block{score, type}, bottomLeft{bottomLeft}, offsets{std::move(offsets)} {}

UnplacedBlock::~UnplacedBlock() {}

void UnplacedBlock::moveDown() {
	--bottomLeft.y;
}

void UnplacedBlock::moveRight() {
	++bottomLeft.x;
}

void UnplacedBlock::moveLeft() {
	--bottomLeft.x;
}

void UnplacedBlock::rotateRight() {
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

void UnplacedBlock::rotateLeft() {
	rotateRight();
	rotateRight();
	rotateRight();
}

int UnplacedBlock::getNumberOfBlocks() {
	return offsets.size();
}
Point UnplacedBlock::getBottomLeft() {
	return bottomLeft;
}

std::vector<Point> UnplacedBlock::pointsOnBoard() const {
	std::vector<Point> points;
	for(auto offset : offsets) {
		points.emplace_back(bottomLeft + offset);
	}
	return points;
}