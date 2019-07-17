#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>
#include <istream>
#include <queue>
#include <thread>

#include "src/interfaces/quadrisState.h"
#include "src/interfaces/game.h"
#include "src/interfaces/commandInterpreter.h"
#include "src/interfaces/subject.h"

class Quadris: public Subject {
	int highScore;
	bool displayingHint;
	std::string curCommand;
	std::string levelFile;

	bool shouldUseTimeDowns;

	GameConfig gameCfg;

	std::unique_ptr<Game> game;
    std::unique_ptr<CommandInterpreter> commandInterpreter;

    std::unique_ptr<std::thread> autoDown;

	int parseMultiplier(std::string);
	std::string parseCommand(std::string);
	void runCommand(CMD);

	friend void loopDown(Quadris* q);

  public:	
  	Quadris(GameConfig cfg);
  	virtual ~Quadris();

	void runGame(std::istream &);
	virtual QuadrisState getState();

};

#endif