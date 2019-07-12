#ifndef INTERFACES_LEVELS_LEVELZERO_H
#define INTERFACES_LEVELS_LEVELZERO_H

#include <fstream>
#include <memory>
#include <string>

#include "interfaces/levelInterface.h"
#include "interfaces/point.h"

const std::string defaultFilename = "sequence.txt";

class LevelZero : public LevelInterface {
	std::unique_ptr<std::fstream> in;

  	std::unique_ptr<UnplacedBlock> getNextBlockImpl(
  		Point bottomLeft) override;

  public:
  	LevelZero(std::string filename = defaultFilename);
};

#endif