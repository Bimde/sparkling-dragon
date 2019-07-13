#ifndef INTERFACES_BOARD_H
#define INTERFACES_BOARD_H

#include <vector>
#include <memory>

class UnplacedBlock;
class PlacedBlock;

class Board {
	std::unique_ptr<UnplacedBlock> currentBlock;
	std::vector<std::vector<std::shared_ptr<PlacedBlock>>> board;

    bool setCurrentIfNotOverlapping(std::unique_ptr<UnplacedBlock>);
    bool rowIsFull(int y);
	bool rowIsEmpty(int y);
	void moveRow(int fromRow, int toRow);

  	std::vector<std::shared_ptr<PlacedBlock>> 
  		destroyFullRowsAndGetDestroyedPlacedBlocks();
  public:
  	Board();

  	void setCurrent(std::unique_ptr<UnplacedBlock>);

  	bool moveCurrentDown();
  	bool moveCurrentLeft();
  	bool moveCurrentRight();
  	bool dropCurrent();
    bool rotateCurrentLeft();
    bool rotateCurrentRight();

    int numberOfFullRows();

  	// Checks if a block overlaps other already placed blocks or is out of bounds
  	bool isOverlapping(const UnplacedBlock&);
	bool isOverlapping(const std::vector<Point>);
	bool isNotOnBoard(const std::vector<Point>);
  	
    // TODO break this up (or make it cleaner)

	int destroyFullRowsAndGetPoints();

    void reset();

    std::vector<std::vector<char>> getState();
};

#endif