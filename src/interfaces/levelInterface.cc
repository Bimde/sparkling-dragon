#include <memory>
#include <utility>

#include "src/interfaces/levelInterface.h"

#include "src/interfaces/board.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

LevelInterface::LevelInterface(int level) : level{level} {}
LevelInterface::~LevelInterface() {}

std::unique_ptr<UnplacedBlock> LevelInterface::getNextBlock(
	Point bottomLeft) {
	return getNextBlockImpl(bottomLeft);
}

int LevelInterface::getLevelNumber() {
	return level;
}

void LevelInterface::actionAfterMoveImpl(Board& board) {}

bool LevelInterface::moveDownImpl(Board& board) {
	return board.moveCurrentDown();
}

bool LevelInterface::moveLeftImpl(Board& board) {
	return board.moveCurrentLeft();
}

bool LevelInterface::moveRightImpl(Board& board) {
	return board.moveCurrentRight();
}

bool LevelInterface::dropImpl(Board& board) {
	return board.dropCurrent();
}

bool LevelInterface::rotateLeftImpl(Board& board) {
	return board.rotateCurrentLeft();
}

bool LevelInterface::rotateRightImpl(Board& board) {
	return board.rotateCurrentRight();
}

// public methods

void LevelInterface::actionAfterMove(Board& board) {
	actionAfterMoveImpl(board);
}

bool LevelInterface::moveDown(Board& board) {
	return moveDownImpl(board);
}

bool LevelInterface::moveLeft(Board& board) {
	return moveLeftImpl(board);
}

bool LevelInterface::moveRight(Board& board) {
	return moveRightImpl(board);
}

bool LevelInterface::drop(Board& board) {
	return dropImpl(board);
}

bool LevelInterface::rotateLeft(Board& board) {
	return rotateLeftImpl(board);
}

bool LevelInterface::rotateRight(Board& board) {
	return rotateRightImpl(board);
}

