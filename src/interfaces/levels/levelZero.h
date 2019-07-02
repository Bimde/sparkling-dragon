#ifndef INTERFACES_LEVELS_LEVELZERO_H
#define INTERFACES_LEVELS_LEVELZERO_H

#include "levelInterface.h"

class LevelZero : public LevelInterface {
  	UnplacedBlock getNextBlockImpl() override;
  	
  public:
  	LevelZero(string filename);
};

#endif