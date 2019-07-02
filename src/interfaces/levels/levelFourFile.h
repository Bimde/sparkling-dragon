#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include <iostream>
#include <memory>

#include "levelFour.h"

class LevelFourFile : public LevelFour {
	std::shared_ptr<istream> in;
	
	std::unique_ptr<UnplacedBlock> getNextBlockImpl() override;
    
  public:
  	LevelFourFile(std::shared_ptr<istream> in);
};

#endif