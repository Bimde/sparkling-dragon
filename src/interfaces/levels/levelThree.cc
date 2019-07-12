#include <fstream>
#include <memory>
#include <string>
#include <cstdlib>

#include "src/interfaces/levels/levelThree.h"

#include "src/interfaces/blockGenerator.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

namespace {
	int kPoints = 3;
	int totalProbability = 9;
}  // namespace

LevelThree::LevelThree() {}
LevelThree::~LevelThree() {}

std::unique_ptr<UnplacedBlock> LevelThree::getNextBlockImpl(
	Point bottomLeft) {
	int randomNumber = rand() % totalProbability;

	switch (randomNumber) {
		// 1/9 probability
		case 0 : return createLetterBlock('I', kPoints, bottomLeft);
		// 1/9 probability
		case 1 : return createLetterBlock('J', kPoints, bottomLeft);
		// 1/9 probability
		case 2 : return createLetterBlock('L', kPoints, bottomLeft);
		// 1/9 probability
		case 3 : return createLetterBlock('O', kPoints, bottomLeft);
		// 1/9 probability
		case 4 : return createLetterBlock('Z', kPoints, bottomLeft);
		// 2/9 probability
		case 5 : return createLetterBlock('S', kPoints, bottomLeft);
		case 6 : return createLetterBlock('S', kPoints, bottomLeft);
		// 2/9 probability
		case 7 : return createLetterBlock('Z', kPoints, bottomLeft);
		case 8 : return createLetterBlock('Z', kPoints, bottomLeft);
	}

	return nullptr;
}

void LevelThree::actionAfterMoveImpl(Board& board) {
	LevelInterface::moveDown(board);
}
