#ifndef INTERFACES_BOARD_H
#define INTERFACES_BOARD_H

#include <vector>
#include <memory>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/placedBlock.h"

class Board {
    int numDropsWithoutClears;

	std::unique_ptr<UnplacedBlock> currentBlock;
	std::vector<std::vector<std::shared_ptr<PlacedBlock>>> board;

    bool rowIsFull(int y) const;
	bool rowIsFullWithUnplacedBlock(int y, const UnplacedBlock&) const;
	bool rowIsEmpty(int y) const;
	void moveRow(int fromRow, int toRow);

  	std::vector<std::shared_ptr<PlacedBlock>> 
  	destroyFullRowsAndGetDestroyedPlacedBlocks();
  public:
  	Board();

  	void setCurrent(std::unique_ptr<UnplacedBlock>);
    bool setCurrentIfNotOverlapping(std::unique_ptr<UnplacedBlock>);

  	bool moveCurrentDown();
  	bool moveCurrentLeft();
  	bool moveCurrentRight();
  	bool dropCurrent();
    bool rotateCurrentLeft();
    bool rotateCurrentRight();

	bool isOverlapping(const UnplacedBlock&) const;

    int numberOfFullRows();
	int numberOfFullRowsWithUnplacedBlock(const UnplacedBlock&) const;
  	int numberOfEmptyRowsWithUnplacedBlock(const UnplacedBlock&) const;

	int currentBlockScore();
	Point currentBlockBottomLeft();

	int destroyFullRowsAndGetPoints();

    bool isGameOver();

    int getNumDropsWithoutClears() ;
    void increaseNumDropsWithoutClears();
    void resetNumDropsWithoutClears();

    UnplacedBlock* getCurrentBlock();

    std::vector<std::vector<char>> getState();
};

#endif