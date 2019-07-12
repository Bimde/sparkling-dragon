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

void LevelInterface::actionAfterMoveImpl(Board& board) {}

void LevelInterface::moveDownImpl(Board& board) {
	board.moveCurrentDown();
}

void LevelInterface::moveLeftImpl(Board& board) {
	board.moveCurrentLeft();
}

void LevelInterface::moveRightImpl(Board& board) {
	board.moveCurrentRight();
}

void LevelInterface::dropImpl(Board& board) {
	board.dropCurrent();
}

void LevelInterface::rotateLeftImpl(Board& board) {
	board.rotateCurrentLeft();
}

void LevelInterface::rotateRightImpl(Board& board) {
	rotateRightImpl(board);
}

// public methods

void LevelInterface::moveDown(Board& board) {
	moveDownImpl(board);
}

void LevelInterface::moveLeft(Board& board) {
	moveLeftImpl(board);
}

void LevelInterface::moveRight(Board& board) {
	moveRightImpl(board);
}

void LevelInterface::drop(Board& board) {
	dropImpl(board);
}

void LevelInterface::rotateLeft(Board& board) {
	rotateLeftImpl(board);
}

void LevelInterface::rotateRight(Board& board) {
	rotateRightImpl(board);
}

void LevelInterface::actionAfterMove(Board& board) {
	actionAfterMoveImpl(board);
}
