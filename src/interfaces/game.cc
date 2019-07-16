#include <memory>
#include <utility>
#include <iostream>

#include "src/interfaces/game.h"
#include "src/interfaces/board.h"
#include "src/interfaces/levelInterface.h"
#include "src/interfaces/hintGenerator.h"
#include "src/interfaces/levelFactory.h"
#include "src/interfaces/gameState.h"
#include "src/interfaces/commands.h"
#include "src/interfaces/levels/blockGenerator.h"

namespace {
	const char hintType = '?';
	const Point defaultSpawnPoint{0,14};
	const int gameBoardDisplayStartingOffset = 3;
	const int boardHeight = 18;
}  // namespace

Game::Game(std::unique_ptr<LevelFactory> levelFactory, 
           std::shared_ptr<HintGenerator> hinter, int startingLevel) :
	levelFactory_{std::move(levelFactory)}, hinter_{std::move(hinter)},
	score{0}, showHint{false}, nextLevel{-1}, numBlocksSpawned{0},
	board{std::make_unique<Board>()} {

	// Initialize other member fields
	nextLevel = levelFactory_->getClosestLevel(startingLevel);
	currentLevel = levelFactory_->getLevel(nextLevel);
	nextBlock = currentLevel->getNextBlock(defaultSpawnPoint); 

	completeTurn();
}

// Sets next level and updates the next block
void Game::completeTurn() {
	if (nextBlock != nullptr) {
		++numBlocksSpawned;
	}

	std::unique_ptr<UnplacedBlock> temp;

	if (nextBlock != nullptr) {
		temp = std::make_unique<UnplacedBlock>(*nextBlock);
	}

	int isValidCurrent = board->setCurrentIfNotOverlapping(std::move(temp));
	
	if (isValidCurrent && nextBlock != nullptr) {
		currentLevel = levelFactory_->getLevel(nextLevel);
		nextBlock = currentLevel->getNextBlock(defaultSpawnPoint);
	}
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
	std::cout << "Starting score: " << score << std::endl;
	if (!currentLevel->drop(*board)) {
		return false;
	}
	
	int numFullRows = board->numberOfFullRows();

	if (numFullRows == 0) {
		board->increaseNumDropsWithoutClears();
	} else {
		std::cout << "Cur score: " << score << std::endl;
		int rowScore = numFullRows + currentLevel->getLevelNumber();
		std::cout << "[Num full rows = " << numFullRows << "][Current level = " << currentLevel->getLevelNumber() << "] Row score: " << rowScore * rowScore << std::endl;
		score += rowScore * rowScore;
		score += board->destroyFullRowsAndGetPoints();
		board->resetNumDropsWithoutClears();
		std::cout << "Final score: " << score << std::endl;
	}

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
	std::vector<std::vector<char>> boardState = board->getState();

	// Draw the hint onto the board if needed
	if (showHint && board->getCurrentBlock() != nullptr && hinter_ != nullptr) {
		UnplacedBlock hint = hinter_->generateHint(*board, 
												   *(board->getCurrentBlock()));

		std::vector<Point> points = hint.pointsOnBoard();
		int boardHeight = boardState.size();
		for (auto p : points) {
			boardState.at(boardHeight - p.y - 1).at(p.x) = hintType;
		}
	}

	std::vector<std::vector<char>> displayBoardState;
	displayBoardState.reserve(boardHeight-gameBoardDisplayStartingOffset);

	for (int i = gameBoardDisplayStartingOffset; i < boardHeight; ++i) {
		displayBoardState.emplace_back(boardState.at(i));
	}

	if (nextBlock == nullptr) {
		return GameState(currentLevel->getLevelNumber(), score, displayBoardState, 
					 	 nextLevel, nullptr, isGameOver());
	}

	return GameState(currentLevel->getLevelNumber(), score, displayBoardState, 
					 nextLevel, std::make_shared<UnplacedBlock>(*nextBlock), 
					 isGameOver());
}

std::unique_ptr<Game> Game::create(GameConfig cfg) {
	auto levelFactory = std::make_unique<LevelFactory>(cfg.getLevelConfig());
	auto hintGenerator = HintGenerator::create();

	if (levelFactory == nullptr || hintGenerator == nullptr) {
		return nullptr;
	}

	return std::make_unique<Game>(std::move(levelFactory), std::move(hintGenerator), 
								  cfg.startLevel());
}

bool Game::isGameOver() {
	return board->isGameOver();
}

int Game::getNumBlocksSpawned() {
	return numBlocksSpawned;
}

void Game::changeCurrentBlock(char ch) {
	board->setCurrentIfNotOverlapping(createLetterBlock(
		ch, board->currentBlockScore(), board->currentBlockBottomLeft()));
}

void Game::changeBlockType(CMD command) {
	switch (command) {
		case SpawnIBlock:
			changeCurrentBlock('I');
			break;
		case SpawnJBlock:
			changeCurrentBlock('J');
			break;
		case SpawnLBlock:
			changeCurrentBlock('L');
			break;
		case SpawnOBlock:
			changeCurrentBlock('O');
			break;
		case SpawnSBlock:
			changeCurrentBlock('S');
			break;
		case SpawnZBlock:
			changeCurrentBlock('Z');
			break;
		case SpawnTBlock:
			changeCurrentBlock('T');
			break;
		default:
			break;
	}
}