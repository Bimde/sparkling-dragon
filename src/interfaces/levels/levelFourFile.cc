#include <memory>

#include "levelFourFile.h"

LevelFourFile::LevelFourFile(std::shared_ptr<istream> in) : in{in} = default;

std::unique_ptr<UnplacedBlock> getNextBlockImpl() {
	// TODO
}