#ifndef INTERFACES_LEVEL_FACTORY_H
#define INTERFACES_LEVEL_FACTORY_H

#include "levelInterface.h"

class LevelFactory {
	std::shared_ptr<LevelInterface> levelOne;
	...
  public:
  	LevelFactory();

  	std::shared_ptr<LevelInterface> getLevel(int level);
};

#endif