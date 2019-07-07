#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include <memory>

#include "levelInterface.h"

class LevelFour : public LevelInterface {
	std::unique_ptr<UnplacedBlock> getNextBlockImpl() override;

    void actionAfterMoveImpl(Board&) override;
    
  public:
  	LevelFour();
  	virtual ~LevelFour();
};

#endif