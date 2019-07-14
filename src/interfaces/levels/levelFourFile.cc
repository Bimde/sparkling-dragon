#include <memory>
#include <fstream>

#include "src/interfaces/levels/levelFourFile.h"

LevelFourFile::LevelFourFile(std::shared_ptr<std::ifstream> in) : 
	in{in} {};

std::unique_ptr<UnplacedBlock> getNextBlockImpl(
	Point bottomLeft) {
	// TODO
}