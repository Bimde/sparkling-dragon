#include <memory>
#include <fstream>

#include "src/interfaces/levelFactory.h"

#include "src/interfaces/levelInterface.h"
#include "src/interfaces/levels/levelZero.h"
#include "src/interfaces/levels/levelOne.h"
#include "src/interfaces/levels/levelTwo.h"
#include "src/interfaces/levels/levelThree.h"
#include "src/interfaces/levels/levelThreeFile.h"
#include "src/interfaces/levels/levelFour.h"
#include "src/interfaces/levels/levelFourFile.h"

namespace {
	const int minLevel = 0;
	const int maxLevel = 4;
}

LevelFactory::LevelFactory(const LevelConfig& cfg) : 
	levelZero{nullptr}, 
	levelOne{std::make_shared<LevelOne>()}, 
	levelTwo{std::make_shared<LevelTwo>()}, 
	levelThree{std::make_shared<LevelThree>()}, 
	levelFour{std::make_shared<LevelFour>()} {

	if (cfg.hasSeed()) {
		srand(cfg.seed());
	}

	if (cfg.hasFilename()) {
		levelZero = std::make_shared<LevelZero>(cfg.filename());
	} else {
		levelZero = std::make_shared<LevelZero>();
	}
}


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

void LevelFactory::useFileForOther(std::string filename) {
	auto filestream = std::make_shared<std::ifstream>(filename);

	levelThree = std::make_shared<LevelThreeFile>(filestream);
	levelFour = std::make_shared<LevelFourFile>(filestream);
}

void LevelFactory::random() {
	levelThree = std::make_shared<LevelThree>();
	levelFour = std::make_shared<LevelFour>();
}

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