#ifndef INTERFACES_LEVEL_INTERFACE_H
#define INTERFACES_LEVEL_INTERFACE_H

#include <memory>
#include <utility>

#include "unplacedBlock.h"
#include "point.h"

class Board;

class LevelInterface {
    int level;

  	virtual std::unique_ptr<UnplacedBlock> getNextBlockImpl(
      Point bottomLeft) = 0;

  	virtual void actionAfterMoveImpl(Board&);

    virtual void moveDownImpl(Board&);
    virtual void moveLeftImpl(Board&);
    virtual void moveRightImpl(Board&);
    virtual void dropImpl(Board&);
    virtual void rotateLeftImpl(Board&);
    virtual void rotateRightImpl(Board&);

  public:
    LevelInterface(int level);
  	virtual ~LevelInterface();

    // Gets the next block to be played based on the current state.
    // Assumes that it called at most once per turn.
    std::unique_ptr<UnplacedBlock> getNextBlock(Point bottomLeft);

    // Moves the current block on the board.
    void moveDown(Board&);
    void moveLeft(Board&);
    void moveRight(Board&);
    void drop(Board&);
    void rotateLeft(Board&);
    void rotateRight(Board&);

    void actionAfterMove(Board&);
};

#endif