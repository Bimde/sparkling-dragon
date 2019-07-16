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

    bool rowIsFull(int y);
	bool rowIsEmpty(int y);
	void moveRow(int fromRow, int toRow);

  	bool isOverlapping(const UnplacedBlock&);

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

    int numberOfFullRows();
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