#include <memory>
#include <utility>

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
	levelFactory{std::move(levelFactory)}, hinter{std::move(hinter)},
	score{0}, showHint{false}, 
	nextLevel{levelFactory->getClosestLevel(startingLevel)},
	currentLevel{levelFactory->getLevel(nextLevel)},
	board{std::make_unique<Board>()}, 
	nextBlock{std::move(currentLevel->getNextBlock(defaultSpawnPoint))} {
	completeTurn();
}

// Sets next level and updates the next block
void Game::completeTurn() {
	currentLevel = levelFactory->getLevel(nextLevel);

	board->setCurrent(std::move(nextBlock));
	nextBlock = std::move(currentLevel->getNextBlock(defaultSpawnPoint));
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

int Game::getScore() {
	return score;
}

bool Game::dropCurrentBlock() {
	if (!board->dropCurrent()) return false;

	int numFullRows = board->numberOfFullRows();
	score += (numFullRows + 1)*(numFullRows + 1);
	score += board->destroyFullRowsAndGetPoints();

	completeTurn();

	return true;
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

void Game::useFileForLevel(std::string filename) {
	levelFactory->useFileForOther(filename);
}

void Game::randomizeLevels() {
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

GameState Game::getState() {
	// TODO check hint (and return with hint if true)
	return GameState(currentLevel->getLevelNumber(), score, board->getState());
}

std::unique_ptr<Game> create(GameConfig cfg) {
	auto levelFactory = std::make_unique<LevelFactory>(cfg.lvlcfg);
	auto hintGenerator = HintGenerator::create();

	if (levelFactory == nullptr || hintGenerator == nullptr) {
		return nullptr;
	}

	return std::make_unique<Game>(std::move(levelFactory), std::move(hintGenerator), 
								  cfg.startLevel());
}