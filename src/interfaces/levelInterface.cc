#include <memory>
#include <utility>

#include "board.h"
#include "levelInterface.h"
#include "unplacedBlock.h"

LevelInterface::LevelInterface(int level) : level{level} {}
LevelInterface::~LevelInterface() {}

std::unique_ptr<UnplacedBlock> LevelInterface::getNextBlock() {
	return getNextBlockImpl();
}

void LevelInterface::actionAfterMoveImpl(Board&) {}

void LevelInterface::moveDown(Board& board) {
	board.moveCurrentDown();
}

void LevelInterface::moveLeft(Board& board) {
	board.moveCurrentLeft();
}

void LevelInterface::moveRight(Board& board) {
	board.moveCurrentRight();
}

void LevelInterface::drop(Board& board) {
	board.dropCurrent();
}

void LevelInterface::rotateLeft(Board& board) {
	board.rotateCurrentLeft();
}

void LevelInterface::rotateRight(Board& board) {
	board.rotateCurrentRight();
}

void LevelInterface::actionAfterMove(Board& board) {
	actionAfterMoveImpl(board);
}
