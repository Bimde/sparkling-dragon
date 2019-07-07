#ifndef INTERFACES_LEVELS_LEVELZERO_H
#define INTERFACES_LEVELS_LEVELZERO_H

#include <iostream>
#include <memory>

#include "levelInterface.h"

class LevelZero : public LevelInterface {
	std::unique_ptr<istream> in;

  	std::unique_ptr<UnplacedBlock> getNextBlockImpl() override;

  public:
  	LevelZero(string filename);
};

#endif