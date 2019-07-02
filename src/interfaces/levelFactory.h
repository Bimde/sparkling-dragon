#ifndef INTERFACES_LEVEL_FACTORY_H
#define INTERFACES_LEVEL_FACTORY_H

#include <string>

#include "levelInterface.h"

struct LevelConfig {
	const std::string filename;

	LevelConfig();
	LevelConfig(std::string filename);
};

class LevelFactory {
	std::shared_ptr<LevelInterface> levelZero;
	std::shared_ptr<LevelInterface> levelOne;
	std::shared_ptr<LevelInterface> levelTwo;
	std::shared_ptr<LevelInterface> levelThree;
	std::shared_ptr<LevelInterface> levelFour;

  public:
  	LevelFactory(LevelConfig cfg);

  	std::shared_ptr<LevelInterface> getLevel(int level);
};

#endif