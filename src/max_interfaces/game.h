#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

// Maybe can improve this using pImpl tbh LOL
struct GameState {
	int score;
	std::vector<std::vector<char>> board;

	// Other fields
};

class Game {
	int score;

	Board board;
	UnplacedBlock nextBlock;

	Level currentLevel;
	Level nextLevel;
  public:
  	Game();

  	GameState getState();

  	// All moves
};

#endif