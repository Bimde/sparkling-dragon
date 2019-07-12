#ifndef INTERFACES_LEVELS_LEVELTWO_H
#define INTERFACES_LEVELS_LEVELTWO_H

#include <memory>

#include "src/interfaces/levelInterface.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class LevelTwo : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
  		Point bottomLeft) override;

  public:
  	LevelTwo();
};

#endif