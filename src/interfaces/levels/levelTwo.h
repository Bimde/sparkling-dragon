#ifndef INTERFACES_LEVELS_LEVELTWO_H
#define INTERFACES_LEVELS_LEVELTWO_H

#include "levelInterface.h"

class LevelTwo : public LevelInterface {
  	UnplacedBlock getNextBlockImpl() override;

  public:
  	LevelTwo();
};

#endif