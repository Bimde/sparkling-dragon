#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include <iostream>
#include <memory>

#include "levelThree.h"

class LevelThreeFile : public LevelThree {
	std::shared_ptr<istream> in;
	
	std::unique_ptr<UnplacedBlock> getNextBlockImpl() override;
    
  public:
  	LevelThreeFile(std::shared_ptr<istream> in);
};

#endif