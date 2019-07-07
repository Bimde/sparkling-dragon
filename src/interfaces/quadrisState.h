#ifndef INTERFACES_QUADRISSTATE_H
#define INTERFACES_QUADRISSTATE_H

#include "gameState.h"

struct QuadrisState {
	const int highScore;
	const GameState gameState;
	
	QuadrisState(int highScore, GameState gameState) : 
		highScore{highScore}, gameState{gameState} {}
};

#endif