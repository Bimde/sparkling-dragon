#ifndef QUADRIS_H
#define QUADRIS_H

#include <memory>
#include <string>

#include "game.h"

class Quadris {
	int highScore;
	std::unique_ptr<Game> game;
  public:
	void sendCommand(std::string s);
	...
	~Quadris();
};

#endif