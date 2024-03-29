#include <fstream>
#include <memory>
#include <string>

#include "src/interfaces/levels/levelZero.h"
#include "src/interfaces/levels/blockGenerator.h"
#include "src/interfaces/levelInterface.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
	const int kLevel = 0;
	const int kPoints = 1;
}  // namespace

LevelZero::LevelZero(std::string filename) : LevelInterface{kLevel} {
	if (!filename.empty()) {
		in = std::make_unique<std::fstream>(filename);
	}
}

std::unique_ptr<UnplacedBlock> LevelZero::getNextBlockImpl(
	Point bottomLeft) {
	if (in == nullptr) {
		return nullptr;
	}

	char type = in->get();

	// Attempt rereading from beginning of file
	if (!in->good()) {
		in->clear();
		in->seekg(0, std::ios::beg);
		type = in->get();
	}

	if (!in->good()) {
		return nullptr;
	}

	return createLetterBlock(type, kPoints, bottomLeft);
}
