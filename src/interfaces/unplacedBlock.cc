#include <vector>
#include <utility>

#include "unplacedBlock.h"
#include "block.h"

UnplacedBlock::UnplacedBlock(
	int score, char type, std::pair<int, int> bottomLeft, 
	std::vector<std::pair<int, int>> offsets) :
	Block{score, type}, bottomLeft{bottomLeft}, offsets{std::move(offsets)} {}

UnplacedBlock::~UnplacedBlock() {}

// TODO
void UnplacedBlock::rotateLeft();
void UnplacedBlock::moveDown();
void UnplacedBlock::moveRight();
void UnplacedBlock::moveLeft();