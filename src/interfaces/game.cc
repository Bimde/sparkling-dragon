#include <memory>
#include <utility>

#include "game.h"
#include "board.h"
#include "levelInterface.h"
#include "levelFactory.h"
#include "gameState.h"

Game::Game(std::unique_ptr<LevelFactory> levelFactory, 
           std::shared_ptr<HintGenerator> hinter, int startingLevel) :
	levelFactory{std::move(levelFactory)}, hinter{std::move(hinter)},
	score{0}, nextLevel{levelFactory->getClosestLevel(startingLevel)},
	showHint{false}, currentLevel{levelFactory->getLevel(nextLevel)} {
	// TODO Init board, next block, etc
}

bool Game::moveCurrentBlockDown() {
	return board->moveCurrentDown();
}

bool Game::moveCurrentBlockLeft() {
	return board->moveCurrentLeft();
}

bool Game::moveCurrentBlockRight() {
	return board->moveCurrentRight();
}

// TODO full impl
bool Game::dropCurrentBlock() {
	// Also update score
	return board->dropCurrent();
}

bool Game::rotateCurrentBlockLeft() {
	return board->rotateCurrentLeft();
}

bool Game::rotateCurrentBlockRight() {
	return board->rotateCurrentRight();
}

void Game::increaseLevel() {
	nextLevel = levelFactory->increaseLevel(nextLevel);
}

void Game::decreaseLevel() {
	nextLevel = levelFactory->decreaseLevel(nextLevel);
}

void Game::useFileForLevel() {
	levelFactory->useFileForOther();
}

void Game::useFileForLevel() {
	levelFactory->random();
}

void Game::enableHint() {
	showHint = true;
}

void Game::disableHint() {
	showHint = false;
}

void Game::doLevelActionAfterMove() {
	currentLevel->actionAfterMove(*board);
}

int getScore() {
	return score;
}
// TODO
void Game::reset();
GameState Game::getState();
