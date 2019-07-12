#include <fstream>
#include <memory>
#include <string>
#include <cstdlib>

#include "src/interfaces/levels/levelTwo.h"

#include "src/interfaces/blockGenerator.h"
#include "src/intefaces/unplacedBlock.h"

namespace {
	const int kLevel = 2;
	const int kPoints = 2;
	const int numberOfBlocks = 7;
}  // namespace

LevelTwo::LevelTwo() : LevelInterface{kLevel}  {}

std::unique_ptr<UnplacedBlock> LevelTwo::getNextBlockImpl(
	Point bottomLeft) {
	int randomNumber = rand() % numberOfBlocks;

	switch (randomNumber) {
		// 1/6 probability
		case 0 : return createLetterBlock('I', kPoints, bottomLeft);
		// 1/6 probability
		case 1 : return createLetterBlock('J', kPoints, bottomLeft);
		// 1/6 probability
		case 2 : return createLetterBlock('L', kPoints, bottomLeft);
		// 1/6 probability
		case 3 : return createLetterBlock('O', kPoints, bottomLeft);
		// 1/6 probability
		case 4 : return createLetterBlock('S', kPoints, bottomLeft);
		// 1/6 probability
		case 5 : return createLetterBlock('Z', kPoints, bottomLeft);
		// 1/6 probability
		case 6 : return createLetterBlock('T', kPoints, bottomLeft);
	}

	return nullptr;
}
