#ifndef INTERFACES_LEVEL_FACTORY_H
#define INTERFACES_LEVEL_FACTORY_H

#include <string>
#include <memory>

#include "levelInterface.h"

class LevelZero;
class LevelOne;
class LevelTwo;
class LevelThree;
class LevelFour;

struct LevelConfig {
	const std::string filename;

	LevelConfig();
	LevelConfig(std::string filename);
};

class LevelFactory {
	std::shared_ptr<LevelZero> levelZero;
	std::shared_ptr<LevelOne> levelOne;
	std::shared_ptr<LevelTwo> levelTwo;
	std::shared_ptr<LevelThree> levelThree;
	std::shared_ptr<LevelFour> levelFour;

  public:
  	LevelFactory(LevelConfig cfg);

  	std::shared_ptr<LevelInterface> getLevel(int level);
};

#endif