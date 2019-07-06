#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>
#include <istream>

#include "game.h"
#include "quadrisState.h"

class Quadris {
	int highScore;
	std::unique_ptr<Game> game;
    std::unique_ptr<CommandInterpreter> commandInterpreter;
  public:
	Quadris(int seed, std::string scriptfile, int startLevel);
	void sendCommand(std::string s);
	void runGame(std::istream &);
	QuadrisState getState();
  	~Quadris();
};

#endif