#ifndef INTERFACES_LEVEL_INTERFACE_H
#define INTERFACES_LEVEL_INTERFACE_H

#include "unplacedBlock.h"

class LevelInterface {
  private:
  	virtual UnplacedBlock getNextBlockImpl() = 0;

  	virtual void moveDownImpl(Board&);
    virtual void moveLeftImpl(Board&);
    virtual void moveRightImpl(Board&);
    virtual void dropImpl(Board&);

  public:
  	virtual ~LevelInterface();

    // Gets the next block to be played based on the current state.
    // Assumes that it called at most once per turn.
    UnplacedBlock getNextBlock() = 0;

    // Moves the current block on the board.
    void moveDown(Board&);
    void moveLeft(Board&);
    void moveRight(Board&);
    void drop(Board&);
};

#endif