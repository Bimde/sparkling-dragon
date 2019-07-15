#ifndef INTERFACES_LEVELS_LEVELFOURFILE_H
#define INTERFACES_LEVELS_LEVELFOURFILE_H

#include <fstream>
#include <memory>

#include "src/interfaces/levels/levelFour.h"
#include "src/interfaces/unplacedBlock.h"

class LevelFourFile : public LevelFour {
	std::shared_ptr<std::ifstream> in;
	
	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
		Point bottomLeft) override;
    
  public:
  	LevelFourFile(std::shared_ptr<std::ifstream> in);
};

#endif