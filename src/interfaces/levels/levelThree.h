#ifndef INTERFACES_LEVELS_LEVELTHREE_H
#define INTERFACES_LEVELS_LEVELTHREE_H

#include "levelInterface.h"

class LevelThree : public LevelInterface {
  	UnplacedBlock getNextBlockImpl() override;

  	void moveDownImpl(Board&) override;
    void moveLeftImpl(Board&) override;
    void moveRightImpl(Board&) override;
    
  public:
  	LevelThree();
};

#endif