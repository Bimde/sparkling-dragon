#ifndef QUADRIS_H
#define QUADRIS_H

#include <utility>

#include "game.h"

struct QuadrisState {
	const int highScore;
	const GameState gameState;
	
	QuadrisState(int highScore, GameState gameState);
};

class Quadris {
	int highScore;
	std::unique_ptr<Game> game;
  public:

};

#endif