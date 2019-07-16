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
}

Board::Board() : currentBlock{nullptr}, board{
	std::vector<std::vector<std::shared_ptr<PlacedBlock>>>(
		boardHeight, std::vector<std::shared_ptr<PlacedBlock>>(
			boardWidth, nullptr))} {
	std::cout << "ran board ctor" << std::endl;
}

void Board::setCurrent(std::unique_ptr<UnplacedBlock> next) {
	currentBlock.swap(next);
}

bool Board::rowIsFull(int y) {
	for(int i = 0; i < boardWidth; ++i) {
		if (board.at(y).at(i) == nullptr) return false;
	}
	return true;
}

bool Board::rowIsEmpty(int y) {
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
		std::cout << "Current block does not exist" << std::endl;
		return false;
	}

	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveDown();
	std::cout << "Move current down called on tempBlock" << std::endl;
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

bool Board::isOverlapping(const UnplacedBlock& block) {
	const std::vector<Point> points = block.pointsOnBoard();
	std::cout << "Check if block is overlapping" << std::endl;

	for (const Point& p : points) {
		if (p.y < 0 || p.y >= boardHeight || p.x < 0 || p.x >= boardWidth) {
			std::cout << p.y << ", " << p.x << " are out of bounds" << std::endl;
			return true;
		}

		if (board.at(p.y).at(p.x) != nullptr) {
			std::cout << board.at(p.y).at(p.x)->getType() << std::endl;
			return true;
		}
	}

	std::cout << "Block is not overlapping" << std::endl;

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

	for (Point& p : currentBlock->pointsOnBoard()) {
		std::cout << "Drop block at " << p.y << " and " << p.x << std::endl;
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
			points += dBlock->getScore();
		}
	}
	return points;
}

std::vector<std::vector<char>> Board::getState() {
	std::cout << "getting board state" << std::endl;

	std::vector<std::vector<char>> charBoard(
		boardHeight, std::vector<char>(boardWidth, ' '));
	for(int y = 0; y < boardHeight; ++y) {
		for(int x = 0; x < boardWidth; ++x) {
			if(board.at(y).at(x) != nullptr) {
				charBoard.at(boardHeight - y - 1).at(x) = board.at(y).at(x)->getType();
			}
		}
	}

	if (currentBlock != nullptr) {
		std::vector<Point> points = currentBlock->pointsOnBoard();
		for (auto p : points) {
			charBoard.at(boardHeight - p.y - 1).at(p.x) = currentBlock->getType();
		}
	}

	return charBoard;
}

bool Board::isGameOver() {
	if (currentBlock != nullptr && isOverlapping(*currentBlock)) {
		return true;
	}

	for (int y = gameBoardHeight - 1; y < boardHeight; ++y) {
		for (int x = gameBoardWidth - 1; x < boardWidth; ++x) {
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