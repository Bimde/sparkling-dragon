#ifndef INTERFACES_UNPLACED_BLOCK_H
#define INTERFACES_UNPLACED_BLOCK_H

#include <vector>

#include "block.h"
#include "point.h"

class UnplacedBlock : public Block {
    // (x,y) coordinates of the blocks bottom left corner 
    Point bottomLeft;
    std::vector<Point> offsets;

  protected:
    UnplacedBlock(int score, char type, Point bottomLeft, 
                  std::vector<Point> offsets);

  public:
  	virtual ~UnplacedBlock() = 0;

  	void moveDown();
  	void moveRight();
  	void moveLeft();
    void rotateLeft();
    void rotateRight();
};

#endif