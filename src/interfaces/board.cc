#include <memory>
#include <vector>

#include "board.h"
#include "unplacedBlock.h"
#include "placedBlock.h"

namespace {
	// 15 rows + 3 extra
	const int boardHeight = 18;
	const int boardWidth = 11;
}

Board::Board() : currentBlock{nullptr}, board{
	std::vector(boardWidth, std::vector<std::shared_ptr<PlacedBlock>>(
		boardHeight, nullptr)} {}

bool Board::setCurrentIfNotOverlapping(std::unique_ptr<UnplacedBlock> block) {
	if (isOverlapping(*block)) {
		return false;
	}

	std::unique_ptr::swap(currentBlock, block);
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

// TODO
bool Board::dropCurrent();
int Board::numberOfFullRows();
bool Board::isOverlapping(const UnplacedBlock& block);
std::vector<std::shared_ptr<PlacedBlock>> 
  		Board::destroyFullRowsAndGetDestroyedPlacedBlocks();
void Board::reset();
std::vector<std::vector<char>> Board::getState();