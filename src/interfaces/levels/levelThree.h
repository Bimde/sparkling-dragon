#ifndef INTERFACES_LEVELS_LEVELTHREE_H
#define INTERFACES_LEVELS_LEVELTHREE_H

#include <memory>

#include "levelInterface.h"

class LevelThree : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl() override;

    void actionAfterMoveImpl(Board&) override;
    
  public:
  	LevelThree();
  	virtual ~LevelThree();
};

#endif