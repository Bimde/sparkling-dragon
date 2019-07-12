#include <fstream>
#include <memory>
#include <string>

#include "levelZero.h"

#include "blockGenerator.h"
#include "interfaces/levelInterface.h"
#include "interfaces/unplacedBlock.h"


namespace {
	const int kLevel = 0;
	const int kPoints = 0;
}  // namespace

LevelZero::LevelZero(std::string filename) : LevelInterface{kLevel} {
	if (!filename.empty()) {
		in = std::make_unique<std::fstream>(filename);
	}
}

// TODO implement file read looping if EOF is hit (and empty file check)
std::unique_ptr<UnplacedBlock> LevelZero::getNextBlockImpl(
	Point bottomLeft) {
	if (in == nullptr) {
		return nullptr;
	}

	char type = in->get();

	if (!in->good()) {
		return nullptr;
	}

	return createLetterBlock(type, kPoints, bottomLeft);
}
