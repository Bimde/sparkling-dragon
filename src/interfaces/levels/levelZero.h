#ifndef INTERFACES_LEVELS_LEVELZERO_H
#define INTERFACES_LEVELS_LEVELZERO_H

#include "levelInterface.h"

class LevelZero : public LevelInterface {
  public:
  	LevelZero(string filename);

  	UnplacedBlock getNextBlockImpl() override;
};

#endif