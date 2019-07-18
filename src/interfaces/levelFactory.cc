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

class LevelFactoryImpl : public LevelFactory {
	std::shared_ptr<LevelInterface> levelZero;
	std::shared_ptr<LevelInterface> levelOne;
	std::shared_ptr<LevelInterface> levelTwo;
	std::shared_ptr<LevelInterface> levelThree;
	std::shared_ptr<LevelInterface> levelFour;

	std::shared_ptr<LevelInterface> getLevelImpl(int level) override;
  	void useFileForOtherImpl(std::string filename) override;
	void randomImpl() override;

  	int getClosestLevelImpl(int level) override;
  	int increaseLevelImpl(int level) override;
  	int decreaseLevelImpl(int level) override;

  public:
  	LevelFactoryImpl(const LevelConfig& cfg);
};

LevelFactoryImpl::LevelFactoryImpl(const LevelConfig& cfg) : 
	levelZero{nullptr}, 
	levelOne{std::make_shared<LevelOne>()}, 
	levelTwo{std::make_shared<LevelTwo>()}, 
	levelThree{std::make_shared<LevelThree>()}, 
	levelFour{std::make_shared<LevelFour>()} {

	// Set the random number generator seed
	if (cfg.hasSeed()) {
		srand(cfg.seed());
	}

	// Set the basic levels input file
	if (cfg.hasFilename()) {
		levelZero = std::make_shared<LevelZero>(cfg.filename());
	} else {
		levelZero = std::make_shared<LevelZero>();
	}
}

std::shared_ptr<LevelInterface> LevelFactoryImpl::getLevelImpl(int level) {
	switch (level) {
		case 0 : return levelZero;
		case 1 : return levelOne;
		case 2 : return levelTwo;
		case 3 : return levelThree;
		case 4 : return levelFour;
	}

	return nullptr;
}

void LevelFactoryImpl::useFileForOtherImpl(std::string filename) {
	auto filestream = std::make_shared<std::ifstream>(filename);

	// Switch the levels to read from the file stream
	levelThree = std::make_shared<LevelThreeFile>(filestream);
	levelFour = std::make_shared<LevelFourFile>(filestream);
}

void LevelFactoryImpl::randomImpl() {
	// Switch the levels to use randomness
	levelThree = std::make_shared<LevelThree>();
	levelFour = std::make_shared<LevelFour>();
}

// returns: the closest valid level to the argument
int LevelFactoryImpl::getClosestLevelImpl(int level) {
	if (level < minLevel) {
		return minLevel;
	}
	if (level > maxLevel) {
		return maxLevel;
	}
	return level;
}

int LevelFactoryImpl::increaseLevelImpl(int level) {
	if (level < maxLevel) {
		return level+1;
	}
	return level;
}

int LevelFactoryImpl::decreaseLevelImpl(int level) {
	if (level > minLevel) {
		return level-1;
	}
	return level;
}
}  // namespace

LevelFactory::LevelFactory() {}

LevelFactory::~LevelFactory() {}

std::shared_ptr<LevelInterface> LevelFactory::getLevel(int level) {
	return getLevelImpl(level);
}

void LevelFactory::useFileForOther(std::string filename) {
	return useFileForOtherImpl(filename);
}

void LevelFactory::random() {
	randomImpl();
}

int LevelFactory::getClosestLevel(int level) {
	return getClosestLevelImpl(level);
}

int LevelFactory::increaseLevel(int level) {
	return increaseLevelImpl(level);
}

int LevelFactory::decreaseLevel(int level) {
	return decreaseLevelImpl(level);
}

std::unique_ptr<LevelFactory> LevelFactory::create(
	const LevelConfig& cfg) {
	return std::make_unique<LevelFactoryImpl>(cfg);
}
