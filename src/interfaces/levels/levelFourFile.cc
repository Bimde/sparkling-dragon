#include <memory>
#include <fstream>
#include <iostream>

#include "src/interfaces/levels/levelFourFile.h"
#include "src/interfaces/levels/blockGenerator.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
	const int kPoints = 25;
}  // namespace

LevelFourFile::LevelFourFile(std::shared_ptr<std::ifstream> in) : 
	in{in} {};

std::unique_ptr<UnplacedBlock> LevelFourFile::getNextBlockImpl(
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