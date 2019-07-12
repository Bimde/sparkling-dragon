#include <fstream>
#include <memory>
#include <string>
#include <cstdlib>

#include "src/interfaces/levels/levelOne.h"

#include "src/interfaces/blockGenerator.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
	const int kLevel = 1;
	const int kPoints = 1;
	const int totalProbability = 12;
}  // namespace

LevelOne::LevelOne() : LevelInterface{kLevel}  {}

std::unique_ptr<UnplacedBlock> LevelOne::getNextBlockImpl(
	Point bottomLeft) {
	int randomNumber = rand() % totalProbability;

	switch (randomNumber) {
		// 1/12 probability
		case 0 : return createLetterBlock('S', kPoints, bottomLeft);
		// 1/12 probability
		case 1 : return createLetterBlock('Z', kPoints, bottomLeft);
		// 1/6 probability
		case 2 : return createLetterBlock('I', kPoints, bottomLeft);
		case 3 : return createLetterBlock('I', kPoints, bottomLeft);
		// 1/6 probability
		case 4 : return createLetterBlock('J', kPoints, bottomLeft);
		case 5 : return createLetterBlock('J', kPoints, bottomLeft);
		// 1/6 probability
		case 6 : return createLetterBlock('L', kPoints, bottomLeft);
		case 7 : return createLetterBlock('L', kPoints, bottomLeft);
		// 1/6 probability
		case 8 : return createLetterBlock('O', kPoints, bottomLeft);
		case 9 : return createLetterBlock('O', kPoints, bottomLeft);
		// 1/6 probability
		case 10 : return createLetterBlock('T', kPoints, bottomLeft);
		case 11 : return createLetterBlock('T', kPoints, bottomLeft);
	}

	return nullptr;
}
