#ifndef INTERFACES_QUADRISSTATE_H
#define INTERFACES_QUADRISSTATE_H

#include <string>
#include "gameState.h"

struct QuadrisState {
	const int highScore;
	const std::string curCommand;
	const GameState gameState;
	
	QuadrisState(int highScore, std::string curCommand, GameState gameState);
};

#endif