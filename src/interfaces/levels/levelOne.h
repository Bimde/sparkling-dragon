#ifndef INTERFACES_LEVELS_LEVELONE_H
#define INTERFACES_LEVELS_LEVELONE_H

#include "levelInterface.h"

class LevelOne : public LevelInterface {
  	UnplacedBlock getNextBlockImpl() override;
  	
  public:
  	LevelOne();
};

#endif