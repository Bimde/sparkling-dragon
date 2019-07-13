#include <memory>
#include <vector>

#include "src/interfaces/board.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/placedBlock.h"

namespace {
	// 15 rows + 3 extra
	const int boardHeight = 18;
	const int boardWidth = 11;
}

bool Board::rowIsFull(int y) {
	for(int i = 0; i < boardWidth; i++) {
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

Board::Board(): currentBlock{nullptr}, board{
	std::vector(boardHeight, std::vector<std::shared_ptr<PlacedBlock>>(boardWidth, nullptr))} {}

bool Board::setCurrentIfNotOverlapping(std::unique_ptr<UnplacedBlock> block) {
	if (isOverlapping(*block)) {
		return false;
	}

	currentBlock.swap(block);
	return true;
}

bool Board::moveCurrentDown() {
	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveDown();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::moveCurrentLeft() {
	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveLeft();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::moveCurrentRight() {
	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->moveRight();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::rotateCurrentLeft() {
	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->rotateLeft();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

bool Board::rotateCurrentRight() {
	auto tempBlock = std::make_unique<UnplacedBlock>(*currentBlock);
	tempBlock->rotateRight();

	return setCurrentIfNotOverlapping(std::move(tempBlock));
}

int Board::numberOfFullRows() {
	int fullRows = 0;
	for(int y = 0; y < board.size(); ++y) {
		if (rowIsFull(y)) fullRows++;
	}
	return fullRows;
}

bool Board::isOverlapping(const UnplacedBlock& block) {
	const std::vector<Point> points = block.pointsOnBoard();
	for(Point p: points) {
		if(board.at(p.y).at(p.x) != nullptr) return false;
	}
	return true;
}

bool Board::dropCurrent() {
	if (!moveCurrentDown()) return false;
	while(moveCurrentDown){};
	return true;
}

std::vector<std::shared_ptr<PlacedBlock>> 
  		Board::destroyFullRowsAndGetDestroyedPlacedBlocks() 
{
	std::vector<std::shared_ptr<PlacedBlock>> destroyedBlocks;
	for (int y = boardHeight - 1; y >= 0; --y) {
		if(rowIsFull(y)) {
			for(int x = 0; x < boardWidth; ++x) {
				destroyedBlocks.emplace_back(board.at(y).at(x));
				board.at(y).at(x) = nullptr;
			}
		}
	}

	int emptyRow = boardHeight-1, shiftRow = 0;

	while(shiftRow >= 0 && emptyRow >= 0 && shiftRow < emptyRow) {
		while(!rowIsEmpty(emptyRow)) emptyRow--;
		shiftRow = emptyRow;
		while(rowIsEmpty(shiftRow)) shiftRow--;		
		moveRow(shiftRow, emptyRow);
	}

	return destroyedBlocks;
}

int Board::destroyFullRowsAndGetPoints() {
	int points = 0;
	std::vector<std::shared_ptr<PlacedBlock>> destroyedBlocks = 
		destroyFullRowsAndGetDestroyedPlacedBlocks();
	for(auto dBlock: destroyedBlocks) {
		dBlock->decrementCount;
		if (dBlock->isDestroyed) {
			points += dBlock->getScore();
		}
	}
	return points;
}

void Board::reset() {
	currentBlock = nullptr;
	for(auto boardRow: board) {
		for(std::shared_ptr<PlacedBlock> block: boardRow) {
			block = nullptr;
		}
	}
}

std::vector<std::vector<char>> Board::getState() {
	std::vector<std::vector<char>> charBoard(boardHeight, std::vector<char>(boardWidth, ' '));
	for(int y = 0; y < boardHeight; ++y) {
		for(int x = 0; x < boardWidth; ++x) {
			if(board.at(y).at(x) != nullptr) {
				charBoard.at(y).at(x) = board.at(y).at(x)->getType();
			}
		}
	}
	return charBoard;
}