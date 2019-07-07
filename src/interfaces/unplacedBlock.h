#ifndef INTERFACES_UNPLACED_BLOCK_H
#define INTERFACES_UNPLACED_BLOCK_H

#include <vector>

#include "block.h"

class UnplacedBlock : public Block {
    std::pair<int, int> bottomLeft;
    std::vector<std::pair<int, int>> offsets;

  protected:
    UnplacedBlock(int score, char type, std::pair<int, int> bottomLeft, 
                  std::vector<std::pair<int, int>> offsets);

  public:
  	virtual ~UnplacedBlock() = 0;

  	void moveDown();
  	void moveRight();
  	void moveLeft();
    void rotateLeft();
    void rotateRight();
};

#endif