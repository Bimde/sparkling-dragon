#ifndef INTERFACES_LEVELS_LEVELONE_H
#define INTERFACES_LEVELS_LEVELONE_H

#include <memory>

#include "levelInterface.h"

class LevelOne : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
  		Point bottomLeft) override;
  	
  public:
  	LevelOne();
};

#endif