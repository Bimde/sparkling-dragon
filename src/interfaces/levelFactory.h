#ifndef INTERFACES_LEVEL_FACTORY_H
#define INTERFACES_LEVEL_FACTORY_H

#include <string>
#include <memory>

#include "src/interfaces/levelInterface.h"
#include "src/interfaces/levels/levelZero.h"
#include "src/interfaces/levels/levelOne.h"
#include "src/interfaces/levels/levelTwo.h"
#include "src/interfaces/levels/levelThree.h"
#include "src/interfaces/levels/levelFour.h"

class LevelConfig {
	int seed_;
	bool hasSeed_;

	std::string filename_;
	bool hasFilename_;

  public:
	LevelConfig() : hasSeed_{false}, hasFilename_{false} {};
	
	int seed() const {
		return seed_;
	}

	void setSeed(int seed) {
		hasSeed_ = true;
		seed_ = seed;
	}

	bool hasSeed() const {
		return hasSeed_;
	}

	std::string filename() const {
		return filename_;
	}

	bool hasFilename() const {
		return hasFilename_;
	}

	void setFilename(std::string filename) {
		hasFilename_ = true;
		filename_ = filename;
	}
};

class LevelFactory {
	std::shared_ptr<LevelInterface> levelZero;
	std::shared_ptr<LevelInterface> levelOne;
	std::shared_ptr<LevelInterface> levelTwo;
	std::shared_ptr<LevelInterface> levelThree;
	std::shared_ptr<LevelInterface> levelFour;

  public:
  	LevelFactory(const LevelConfig& cfg);

  	std::shared_ptr<LevelInterface> getLevel(int level);

  	// Sets the input as a file for certain levels
  	void useFileForOther(std::string filename);
  	// Makes certain levels random.
  	void random();

  	int getClosestLevel(int level);
  	int increaseLevel(int level);
  	int decreaseLevel(int level);
};

#endif