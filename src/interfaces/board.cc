#include <memory>
#include <vector>
#include <iostream>

#include "src/interfaces/board.h"
#include "src/interfaces/point.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/placedBlock.h"

namespace {
	// 15 rows + 3 extra
	const int boardHeight = 18;
	const int boardWidth = 11;

	const int gameBoardHeight = 15;
	const int gameBoardWidth = 11;
	const char emptySpot = ' ';
}

Board::Board() : currentBlock{nullptr}, board{
	std::vector<std::vector<std::shared_ptr<PlacedBlock>>>(
		boardHeight, std::vector<std::shared_ptr<PlacedBlock>>(
			boardWidth, nullptr))} {}

void Board::setCurrent(std::unique_ptr<UnplacedBlock> next) {
	currentBlock.swap(next);
}

bool Board::rowIsFull(int y) const {
	for(int i = 0; i < boardWidth; ++i) {
		if (board.at(y).at(i) == nullptr) {
			return false;
		}
	}
	return true;
}

bool Board::rowIsFullWithUnplacedBlock(int y, const UnplacedBlock& block)
	const {
	for(int i = 0; i < boardWidth; ++i) {
		bool blockAtPosition = false;
		for(Point p: block.pointsOnBoard()) {
			if (y == p.y && i == p.x) {
				blockAtPosition = true;
			}
		}
		if (board.at(y).at(i) == nullptr && !blockAtPosition) {
			return false;
		}
	}
	return true;
}

bool Board::rowIsEmpty(int y) const {
	for(int i = 0; i < boardWidth; i++) {
		if (board.at(y).at(i) != nullptr) return false;
	}
	return true;
}

void Board::moveRow(int fromRow, int toRow) {
	for(int i = 0; i < boardWidth; i++) {
		board.at(toRow).at(i) = board.at(fromRow).at(i); 
		board.at(fromRow).at(i) = nullptr;
	}
}

bool Board::setCurrentIfNotOverlapping(std::unique_ptr<UnplacedBlock> block) {
	if (block == nullptr) {
		currentBlock.swap(block);
		return true;
	}

	if (isOverlapping(*block)) {
		return false;
	}

	currentBlock.swap(block);
	return true;
}

bool Board::moveCurrentDown() {
	if (currentBlock == nullptr) {
		return false;
	}

	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveDown();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::moveCurrentLeft() {
	if (currentBlock == nullptr) {
		return false;
	}

	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveLeft();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::moveCurrentRight() {
	if (currentBlock == nullptr) {
		return false;
	}

	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveRight();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::rotateCurrentLeft() {
	if (currentBlock == nullptr) {
		return false;
	}

	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->rotateLeft();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::rotateCurrentRight() {
	if (currentBlock == nullptr) {
		return false;
	}

	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->rotateRight();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

int Board::numberOfFullRows() {
	int fullRows = 0;
	for(int y = 0; y < boardHeight; ++y) {
		if (rowIsFull(y)) {
			++fullRows;
		}
	}
	return fullRows;
}

int Board::numberOfFullRowsWithUnplacedBlock(
	const UnplacedBlock& hintBlock) const {
	int fullRows = 0;
	for(int y = 0; y < boardHeight; ++y) {
		if (rowIsFullWithUnplacedBlock(y, hintBlock)) {
			++fullRows;
		}
	}
	return fullRows;
}

bool Board::isOverlapping(const UnplacedBlock& block) const {
	const std::vector<Point> points = block.pointsOnBoard();

	for (const Point& p : points) {
		if (p.y < 0 || p.y >= boardHeight || p.x < 0 || 
			p.x >= boardWidth) {
			return true;
		}

		if (board.at(p.y).at(p.x) != nullptr) {
			return true;
		}
	}

	return false;
}

bool Board::dropCurrent() {
	if (currentBlock == nullptr) {
		return false;
	}

	if (isOverlapping(*currentBlock)) {
		return false;
	}

	while (moveCurrentDown()) {}

	auto pb = std::make_shared<PlacedBlock>(currentBlock->getScore(), 
		currentBlock->getType(), currentBlock->getNumberOfBlocks()); 

	// Place the current block onto the board
	for (Point& p : currentBlock->pointsOnBoard()) {
		board.at(p.y).at(p.x) = pb;
	}

	currentBlock = nullptr;

	return true;
}

std::vector<std::shared_ptr<PlacedBlock>> 
  		Board::destroyFullRowsAndGetDestroyedPlacedBlocks() 
{
	std::vector<std::shared_ptr<PlacedBlock>> destroyedBlocks;
	for (int y = 0; y < boardHeight; ++y) {
		if (rowIsFull(y)) {
			for(int x = 0; x < boardWidth; ++x) {
				destroyedBlocks.emplace_back(board.at(y).at(x));
				board.at(y).at(x) = nullptr;
			}
		}
	}

	int emptyRow = 0, shiftRow = boardHeight-1;
	
	while (shiftRow < boardHeight && emptyRow < boardHeight && 
		   shiftRow > emptyRow) {
		while (emptyRow < boardHeight && !rowIsEmpty(emptyRow)) {
			++emptyRow;
		}
		shiftRow = emptyRow;

		while (shiftRow < boardHeight && rowIsEmpty(shiftRow)) {
			++shiftRow;
		}

		if (emptyRow < boardHeight && shiftRow < boardHeight) {
			moveRow(shiftRow, emptyRow);
		}
	}

	return destroyedBlocks;
}

int Board::destroyFullRowsAndGetPoints() {
	int points = 0;
	std::vector<std::shared_ptr<PlacedBlock>> destroyedBlocks = 
		destroyFullRowsAndGetDestroyedPlacedBlocks();
	for(auto dBlock : destroyedBlocks) {
		dBlock->decrementCount();
		if (dBlock->isDestroyed()) {
			std::cout << "Block score: " << dBlock->getScore() << std::endl;
			points += dBlock->getScore();
		}
	}
	std::cout << "Total blocks score: " << points << std::endl;
	return points;
}

// returns: the board state represented by its characters 
std::vector<std::vector<char>> Board::getState() {
	std::vector<std::vector<char>> charBoard(
		boardHeight, std::vector<char>(boardWidth, emptySpot));
	
	// Adds all blocks currently placed on the board
	for(int y = 0; y < boardHeight; ++y) {
		for(int x = 0; x < boardWidth; ++x) {
			if(board.at(y).at(x) != nullptr) {
				charBoard.at(boardHeight - y - 1).at(x) = 
					board.at(y).at(x)->getType();
			}
		}
	}

	if (currentBlock != nullptr) {
		// Adds the current (unplaced) block to the board state
		std::vector<Point> points = currentBlock->pointsOnBoard();
		for (auto p : points) {
			charBoard.at(boardHeight - p.y - 1).at(p.x) = 
				currentBlock->getType();
		}
	}

	return charBoard;
}

bool Board::isGameOver() {
	if (currentBlock != nullptr && isOverlapping(*currentBlock)) {
		return true;
	}

	// Checks if any of the blocks on the board is outside of the
	// allocated regions
	for (int y = gameBoardHeight - 1; y < boardHeight; ++y) {
		for (int x = 0; x < gameBoardWidth; ++x) {
			if (board.at(y).at(x) != nullptr) {
				return true;
			}
		}
	}

	return false;
}

int Board::getNumDropsWithoutClears() {
	return numDropsWithoutClears;
}

void Board::increaseNumDropsWithoutClears() {
	++numDropsWithoutClears;
}

void Board::resetNumDropsWithoutClears() {
	numDropsWithoutClears = 0;
}

int Board::currentBlockScore() {
	return currentBlock->getScore();
}

Point Board::currentBlockBottomLeft() {
	return currentBlock->getBottomLeft();
}

UnplacedBlock* Board::getCurrentBlock() {
	return currentBlock.get();
}