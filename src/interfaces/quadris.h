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
  	
  	~Quadris();
	void sendCommand(std::string s);
	...

	QuadrisState getState();
};

#endif