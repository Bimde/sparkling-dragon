#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include <memory>

#include "src/interfaces/levelInterface.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/board.h"

class LevelFour : public LevelInterface {
	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
		Point bottomLeft) override;

	bool dropImpl(Board&) override;
    void actionAfterMoveImpl(Board&) override;
    
  public:
  	LevelFour();
  	virtual ~LevelFour();
};

#endif