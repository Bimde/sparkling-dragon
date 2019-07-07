#include <memory>

#include "levelInterface.h"

LevelFour::LevelFour() = default;
LevelFour::~LevelFour() = default;

std::unique_ptr<UnplacedBlock> getNextBlockImpl() {
	// TODO
}

void LevelFour::moveLeftImpl(Board& board) {
	LevelInterface::moveLeftImpl(board);
	LevelInterface::moveDownImpl(board);
}


void LevelFour::moveRightImpl(Board& board) {
	LevelInterface::moveRightImpl(board);
	LevelInterface::moveDownImpl(board);
}

void LevelFour::dropImpl(Board& board) {
	// TODO add star block
	LevelInterface::dropImpl(board);
}