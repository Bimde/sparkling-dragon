#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include <fstream>
#include <memory>

#include "src/interfaces/levels/levelFour.h"

class LevelFourFile : public LevelFour {
	std::shared_ptr<ifstream> in;
	
	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
		Point bottomLeft) override;
    
  public:
  	LevelFourFile(std::shared_ptr<ifstream> in);
};

#endif