#ifndef INTERFACES_LEVELS_LEVELTHREE_H
#define INTERFACES_LEVELS_LEVELTHREE_H

#include "levelInterface.h"

class LevelThree : public LevelInterface {
  public:
  	LevelThree();
  	UnplacedBlock getNextBlock() override;
};

#endif