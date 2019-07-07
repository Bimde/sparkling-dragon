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

class LevelConfig {
	int seed_;
	std::string filename_;

  public:
	LevelConfig() {}
	
	int seed() {
		return seed_;
	}

	void setSeed(int seed) {
		seed_ = seed;
	}

	std::string filename() {
		return filename_;
	}

	void setFilename(std::string filename) {
		filename_ = filename;
	}
};

class LevelFactory {
	std::shared_ptr<LevelZero> levelZero;
	std::shared_ptr<LevelOne> levelOne;
	std::shared_ptr<LevelTwo> levelTwo;
	std::shared_ptr<LevelThree> levelThree;
	std::shared_ptr<LevelFour> levelFour;

  public:
  	LevelFactory(const LevelConfig& cfg);

  	std::shared_ptr<LevelInterface> getLevel(int level);

  	// Sets the input as a file for certain levels
  	void useFileForOther(std::string filename);
  	// Makes certain levels random.
  	void random();

  	int increaseLevel(int level);
  	int decreaseLevel(int level);
};

#endif