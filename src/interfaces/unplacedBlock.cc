#include <vector>
#include <utility>
#include <climits>

#include "unplacedBlock.h"
#include "block.h"
#include "point.h"

UnplacedBlock::UnplacedBlock(
	int score, char type, Point bottomLeft, std::vector<Point> offsets) :
	Block{score, type}, bottomLeft{bottomLeft}, offsets{std::move(offsets)} {}

UnplacedBlock::~UnplacedBlock() {}

void UnplacedBlock::moveDown() {
	++bottomLeft.y;
}
void UnplacedBlock::moveUp() {
	--bottomLeft.y;
}


void UnplacedBlock::moveRight() {
	++bottomLeft.x;
}

void UnplacedBlock::moveLeft() {
	--bottomLeft.x;
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

Point UnplacedBlock::getBottomLeft() {
	return Point(bottomLeft.x, bottomLeft.y);
}

std::vector<Point> UnplacedBlock::pointsOnBoard() const {
	std::vector<Point> points;
	for(auto offset: offsets) {
		points.emplace_back(new Point(offset.x + bottomLeft.x, offset.y + bottomLeft.y));
	}
	return points;
}

std::vector<Point> UnplacedBlock::getPointsWithOneShiftDown() const {
	std::vector<Point> points;
	for(auto offset: offsets) {
		points.emplace_back(new Point(offset.x + bottomLeft.x, offset.y + bottomLeft.y + 1));
	}
	return points;
}