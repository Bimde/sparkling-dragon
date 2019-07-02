#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>

#include "game.h"
#include "quadrisState.h"

class Quadris {
	int highScore;
	std::unique_ptr<Game> game;
  public:
	Quadris(int seed, std::string scriptfile, int startLevel);
	void sendCommand(std::string s);
	QuadrisState getState();
  	~Quadris();
};

#endif