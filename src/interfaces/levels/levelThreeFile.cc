#include <memory>
#include <fstream>

#include "src/interfaces/levels/levelThreeFile.h"

LevelThreeFile::LevelThreeFile(std::shared_ptr<std::ifstream> in) : 
	in{in} {};

std::unique_ptr<UnplacedBlock> LevelThreeFile::getNextBlockImpl(
	Point bottomLeft) {
	// TODO
}