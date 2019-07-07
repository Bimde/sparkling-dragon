#include <memory>

#include "levelFactory.h"

namespace {
	const int minLevel = 0;
	const int maxLevel = 4;
}

// TODO MIL
LevelFactory::LevelFactory(const LevelConfig& cfg) :

std::shared_ptr<LevelInterface> LevelFactory::getLevel(int level) {
	switch (level) {
		case 0 : return levelZero;
		case 1 : return levelOne;
		case 2 : return levelTwo;
		case 3 : return levelThree;
		case 4 : return levelFour;
	}

	return nullptr;
}

// TODO
void LevelFactory::useFileForOther(std::string filename);
void LevelFactory::random();

int LevelFactory::getClosestLevel(int level) {
	if (level < minLevel) {
		return minLevel;
	}
	if (level > maxLevel) {
		return maxLevel;
	}
	return level;
}

int LevelFactory::increaseLevel(int level) {
	if (level < maxLevel) {
		return level+1;
	}
	return level;
}

int LevelFactory::decreaseLevel(int level) {
	if (level > minLevel) {
		return level-1;
	}
	return level;
}