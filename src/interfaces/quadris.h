#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>
#include <istream>
#include <queue>

#include "game.h"
#include "quadrisState.h"

enum CMD{Left, Right, Down, CW, CCW, Drop, LevelUp, LevelDown, NoRandom, Random, Restart, Hint, RemoveHint, InvalidCommand, AfterMoveTurn};

class Quadris: public Subject {
	int highScore;
	bool displayingHint;
	std::string curCommand;

	std::queue<CMD> commands;

	std::unique_ptr<Game> game;
    std::unique_ptr<CommandInterpreter> commandInterpreter;

	int parseMultiplier(std::string command);
	std::string parseCommand(std::string command);
	void runCommands();
  public:
	Quadris(int seed, std::string scriptfile, int startLevel, std::unique_ptr<CommandInterpreter> cmdInterpreter);
	void sendCommand(std::string s);
	void runGame(std::istream &);
	QuadrisState getState();
  	~Quadris();
};

#endif