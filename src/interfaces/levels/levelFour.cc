#include <memory>
#include <cstdlib>

#include "src/interfaces/levels/levelFour.h"
#include "src/interfaces/levels/blockGenerator.h"
#include "src/interfaces/levelInterface.h"
#include "src/interfaces/point.h"

namespace {
	const int kLevel = 4;
	const int kPoints = 25;
	const int totalProbability = 9;
}  // namespace

LevelFour::LevelFour() : LevelInterface{kLevel} {}
LevelFour::~LevelFour() {}

std::unique_ptr<UnplacedBlock> LevelFour::getNextBlockImpl(
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

bool LevelFour::dropImpl(Board& board) {
	// TODO drop block AND insert valid star block
}

void LevelFour::actionAfterMoveImpl(Board& board) {
	LevelInterface::moveDown(board);
}
