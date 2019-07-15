#include <memory>
#include <utility>
#include <iostream>

#include "src/interfaces/game.h"
#include "src/interfaces/board.h"
#include "src/interfaces/levelInterface.h"
#include "src/interfaces/hintGenerator.h"
#include "src/interfaces/levelFactory.h"
#include "src/interfaces/gameState.h"

namespace {
	const Point defaultSpawnPoint{0,14}; 
	const Point centerSpawnPoint{5,14}; 
}  // namespace

Game::Game(std::unique_ptr<LevelFactory> levelFactory, 
           std::shared_ptr<HintGenerator> hinter, int startingLevel) :
	levelFactory_{std::move(levelFactory)}, hinter_{std::move(hinter)},
	score{0}, showHint{false}, nextLevel{-1},
	board{std::make_unique<Board>()} {

    std::cout << "game object ctor running" << std::endl;

	nextLevel = levelFactory_->getClosestLevel(startingLevel);
	currentLevel = levelFactory_->getLevel(nextLevel);
	nextBlock = currentLevel->getNextBlock(defaultSpawnPoint); 

    std::cout << "game args init" << std::endl;

	completeTurn();

	std::cout << "game object ctor completed" << std::endl;
}

// Sets next level and updates the next block
void Game::completeTurn() {
	currentLevel = levelFactory_->getLevel(nextLevel);

	board->setCurrent(std::move(nextBlock));
	nextBlock = currentLevel->getNextBlock(defaultSpawnPoint);
}

int Game::getScore() {
	return score;
}

bool Game::moveCurrentBlockDown() {
	return currentLevel->moveDown(*board);
}

bool Game::moveCurrentBlockLeft() {
	return currentLevel->moveLeft(*board);
}

bool Game::moveCurrentBlockRight() {
	return currentLevel->moveRight(*board);
}

bool Game::dropCurrentBlock() {
	std::cout << "trying to drop" << std::endl;
	if (!currentLevel->drop(*board)) {
		return false;
	}
	std::cout << "finished drop" << std::endl;

	int numFullRows = board->numberOfFullRows();
	score += (numFullRows + 1)*(numFullRows + 1);
	score += board->destroyFullRowsAndGetPoints();

	completeTurn();

	return true;
}

bool Game::rotateCurrentBlockLeft() {
	return currentLevel->rotateLeft(*board);
}

bool Game::rotateCurrentBlockRight() {
	return currentLevel->rotateRight(*board);
}

void Game::increaseLevel() {
	nextLevel = levelFactory_->increaseLevel(nextLevel);
}

void Game::decreaseLevel() {
	nextLevel = levelFactory_->decreaseLevel(nextLevel);
}

void Game::useFileForLevel(std::string filename) {
	levelFactory_->useFileForOther(filename);
}

void Game::randomizeLevels() {
	levelFactory_->random();
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

GameState Game::getState() {
	// TODO check hint (and return with hint if true)
	std::cout << "getting game state" << std::endl;

	if (currentLevel == nullptr) {
		std::cout << "ERROR: current level is nullptr" << std::endl;
	}

	if (board == nullptr) {
		std::cout << "ERROR: board is nullptr" << std::endl;
	}

	return GameState(currentLevel->getLevelNumber(), score, board->getState(), 
					 nextLevel, std::make_shared<UnplacedBlock>(*nextBlock));
}

std::unique_ptr<Game> Game::create(GameConfig cfg) {
	std::cout << "running game::create factory fn" << std::endl;
	auto levelFactory = std::make_unique<LevelFactory>(cfg.getLevelConfig());
	auto hintGenerator = HintGenerator::create();

	if (levelFactory == nullptr || hintGenerator == nullptr) {
		std::cout << "ERROR: levelfactory ptr or hintgen ptr null" << std::endl;
		return nullptr;
	}

	return std::make_unique<Game>(std::move(levelFactory), std::move(hintGenerator), 
								  cfg.startLevel());
}