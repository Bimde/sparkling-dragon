#ifndef INTERFACES_LEVELS_LEVELTWO_H
#define INTERFACES_LEVELS_LEVELTWO_H

#include <memory>

#include "interfaces/levelInterface.h"
#include "interfaces/unplacedBlock.h"
#include "interfaces/point.h"

class LevelTwo : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
  		Point bottomLeft) override;

  public:
  	LevelTwo();
};

#endif