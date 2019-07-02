#ifndef INTERFACES_GAMESTATE_H
#define INTERFACES_GAMESTATE_H

#include <vector>

struct GameState {
	const int currentLevel;
	const int score;
	const std::vector<std::vector<char>> board;

	GameState(int currentLevel, int score, 
			  std::vector<std::vector<char>> board);
};

#endif