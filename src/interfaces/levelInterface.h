#ifndef INTERFACES_LEVEL_INTERFACE_H
#define INTERFACES_LEVEL_INTERFACE_H

#include "unplacedBlock.h"

class LevelInterface {
  public:
  	virtual ~LevelInterface();

    virtual UnplacedBlock getNextBlock() = 0;

    virtual void moveDown(Board&);
    virtual void moveLeft(Board&);
    virtual void moveRight(Board&);
    void drop(Board&);
};

#endif