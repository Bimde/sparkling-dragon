#ifndef INTERFACES_UNPLACED_BLOCK_H
#define INTERFACES_UNPLACED_BLOCK_H

#include <vector>

#include "src/interfaces/block.h"
#include "src/interfaces/point.h"

class UnplacedBlock : public Block {
    // (y,x) coordinates of the blocks bottom left corner 
    Point bottomLeft;
    std::vector<Point> offsets;

  protected:
    UnplacedBlock(int score, char type, Point bottomLeft, 
                  std::vector<Point> offsets);

  public:
  	virtual ~UnplacedBlock();

  	void moveDown();
  	void moveRight();
  	void moveLeft();
    void rotateLeft();
    void rotateRight();
    int getNumberOfBlocks();
    Point getBottomLeft();
    std::vector<Point> pointsOnBoard() const;
};

#endif