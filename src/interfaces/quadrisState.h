#ifndef INTERFACES_QUADRISSTATE_H
#define INTERFACES_QUADRISSTATE_H

#include <string>
#include <iostream>

#include "gameState.h"

struct QuadrisState {
	int highScore;
	std::string curCommand;
	GameState gameState;
	
	QuadrisState(int highScore, std::string curCommand, GameState gameState) : 
		highScore{highScore}, curCommand{curCommand}, gameState{gameState} {}
};

#endif