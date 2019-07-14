#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>
#include <istream>
#include <queue>

#include "game.h"
#include "src/interfaces/quadrisState.h"
#include "src/ui/subject.h"
#include "src/interfaces/commandInterpreter.h"

// TODO: need to create ctor with `game` 
class Quadris: public Subject {
	int highScore;
	bool displayingHint;
	std::string curCommand;
	std::string levelFile;

	std::unique_ptr<Game> game;
    std::unique_ptr<CommandInterpreter> commandInterpreter;

	int parseMultiplier(std::string);
	std::string parseCommand(std::string);
	void runCommand(CMD);

  public:	
  	Quadris();
	// Quadris(int seed, std::string scriptfile, int startLevel, std::unique_ptr<CommandInterpreter> cmdInterpreter);
	void runGame(std::istream &);
	QuadrisState getState();
  	~Quadris();
};

#endif