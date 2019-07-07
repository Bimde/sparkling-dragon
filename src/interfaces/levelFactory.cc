#include <memory>

#include "levelFactory.h"

// TODO MIL
namespace {
	const int minLevel = 0;
	const int maxLevel = 4;
}

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