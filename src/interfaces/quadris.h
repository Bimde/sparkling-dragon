#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>
#include <istream>
#include <queue>

#include "game.h"
#include "quadrisState.h"
#include "../ui/subject.h"
#include "commandInterpreter.h"

enum CMD{ 
			Left, Right, Down, RotateLeft, RotateRight, Drop, 
		  	LevelUp, LevelDown, NoRandom, Random, Restart, 
		  	Hint, RemoveHint, InvalidCommand, AfterMoveTurn
		};

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
	// Quadris(int seed, std::string scriptfile, int startLevel, std::unique_ptr<CommandInterpreter> cmdInterpreter);
	void runGame(std::istream &);
	QuadrisState getState();
  	~Quadris();
};

#endif