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
	virtual std::shared_ptr<LevelInterface> getLevelImpl(int level) = 0;
  	virtual void useFileForOtherImpl(std::string filename) = 0;
	virtual void randomImpl() = 0;

  	virtual int getClosestLevelImpl(int level) = 0;
  	virtual int increaseLevelImpl(int level) = 0;
  	virtual int decreaseLevelImpl(int level) = 0;

  public:
  	LevelFactory();
  	virtual ~LevelFactory();

  	std::shared_ptr<LevelInterface> getLevel(int level);

  	// Sets the input as a file for certain levels
  	void useFileForOther(std::string filename);

  	// Makes certain levels random.
  	void random();

  	// returns: the closest valid level to the one passed in
  	int getClosestLevel(int level);
  	int increaseLevel(int level);
  	int decreaseLevel(int level);

  	static std::unique_ptr<LevelFactory> create(const LevelConfig& cfg);
};

#endif