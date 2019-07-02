#ifndef INTERFACES_LEVELS_LEVELTWO_H
#define INTERFACES_LEVELS_LEVELTWO_H

#include <memory>

#include "levelInterface.h"

class LevelTwo : public LevelInterface {
  	std::unique_ptr<UnplacedBlock> getNextBlockImpl() override;

  public:
  	LevelTwo();
};

#endif