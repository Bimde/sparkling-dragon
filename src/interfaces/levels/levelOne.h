#ifndef INTERFACES_LEVELS_LEVELONE_H
#define INTERFACES_LEVELS_LEVELONE_H

#include "levelInterface.h"

class LevelOne : public LevelInterface {
  public:
  	LevelOne();
  	
  	UnplacedBlock getNextBlockImpl() override;
};

#endif