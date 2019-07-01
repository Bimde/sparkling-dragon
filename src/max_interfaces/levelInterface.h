#ifndef INTERFACES_LEVEL_INTERFACE_H
#define INTERFACES_LEVEL_INTERFACE_H

#include "unplacedBlock.h"

class LevelInterface {
  public:
  	virtual ~LevelInterface() = 0;

    UnplacedBlock getNextBlock();

    void moveDown(Board&);
    void moveLeft(Board&);
    void moveRight(Board&);
    void drop(Board&);
};

#endif