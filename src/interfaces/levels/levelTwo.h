#ifndef INTERFACES_LEVELS_LEVELTWO_H
#define INTERFACES_LEVELS_LEVELTWO_H

#include "levelInterface.h"

class LevelTwo : public LevelInterface {
  public:
  	LevelTwo();
  	
  	UnplacedBlock getNextBlockImpl() override;
};

#endif