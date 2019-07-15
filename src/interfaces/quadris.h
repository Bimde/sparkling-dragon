#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>
#include <istream>
#include <queue>

#include "src/interfaces/quadrisState.h"
#include "src/interfaces/game.h"
#include "src/interfaces/commandInterpreter.h"
#include "src/interfaces/subject.h"

// TODO: need to create ctor with `game` 
class Quadris: public Subject {
	int highScore;
	bool displayingHint;
	std::string curCommand;
	std::string levelFile;

	GameConfig gameCfg;

	// TODO remove this comment
	// NOTE: to reset the game, we can just create a new one 
	// (I removed Game::reset(), since its a pain to impl that).
	std::unique_ptr<Game> game;
    std::unique_ptr<CommandInterpreter> commandInterpreter;

	int parseMultiplier(std::string);
	std::string parseCommand(std::string);
	void runCommand(CMD);

  public:	
  	Quadris(GameConfig cfg);
  	virtual ~Quadris();

	void runGame(std::istream &);
	virtual QuadrisState getState();
};

#endif