#include <memory>

#include "levelInterface.h"

LevelFour::LevelFour() = default;
LevelFour::~LevelFour() = default;

std::unique_ptr<UnplacedBlock> getNextBlockImpl() {
	// TODO
}

void LevelFour::actionAfterMoveImpl(Board&) {
	LevelInterface::moveDown(board);
}
