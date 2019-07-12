#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include <fstream>
#include <memory>

#include "levelThree.h"

#include "interfaces/point.h"

class LevelThreeFile : public LevelThree {
	std::shared_ptr<fstream> in;
	
	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
		Point bottomLeft) override;
    
  public:
  	LevelThreeFile(std::shared_ptr<ifstream> in);
};

#endif