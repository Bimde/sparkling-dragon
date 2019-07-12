#ifndef INTERFACES_LEVELS_LEVELTHREE_H
#define INTERFACES_LEVELS_LEVELTHREE_H

#include <memory>

#include "src/interfaces/levelInterface.h"
#include "src/interfaces/point.h"

class LevelThree : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
  		Point bottomLeft) override;

    void actionAfterMoveImpl(Board&) override;
    
  public:
  	LevelThree();
  	virtual ~LevelThree();
};

#endif