#ifndef INTERFACES_LEVELS_LEVELTHREE_H
#define INTERFACES_LEVELS_LEVELTHREE_H

#include <memory>

#include "levelInterface.h"
#include "point.h"

class LevelThree : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
  		Point bottomLeft) override;

    void actionAfterMoveImpl(Board&) override;
    
  public:
  	LevelThree();
  	virtual ~LevelThree();
};

#endif