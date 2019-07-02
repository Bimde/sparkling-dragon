#ifndef INTERFACES_LEVEL_INTERFACE_H
#define INTERFACES_LEVEL_INTERFACE_H

#include "unplacedBlock.h"

class LevelInterface {
  public:
  	virtual ~LevelInterface();

    virtual UnplacedBlock getNextBlock() = 0;

    void moveDown(Board&);
    void moveLeft(Board&);
    void moveRight(Board&);
    void drop(Board&);
};

#endif