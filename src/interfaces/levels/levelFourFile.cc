#include <memory>

#include "levelFourFile.h"

LevelFourFile::LevelFourFile(std::shared_ptr<istream> in) : 
	in{in} {};

std::unique_ptr<UnplacedBlock> getNextBlockImpl(
	Point bottomLeft) {
	// TODO
}