#ifndef INTERFACES_GAMESTATE_H
#define INTERFACES_GAMESTATE_H

#include <vector>
#include <utility>
#include <memory>

struct GameState {
	int currentLevel;
	int score;
	std::vector<std::vector<char>> board;

	int nextLevel;
	std::shared_ptr<UnplacedBlock> nextBlock;

	bool isGameOver;

	GameState(int currentLevel, int score, std::vector<std::vector<char>> board,
			  int nextLevel, std::shared_ptr<UnplacedBlock> nextBlock, 
			  bool isGameOver) : 
		currentLevel{currentLevel}, score{score}, board{std::move(board)}, 
		nextLevel{nextLevel}, nextBlock{nextBlock}, isGameOver{isGameOver} {}
};

#endif