#ifndef INTERFACES_LEVEL_INTERFACE_H
#define INTERFACES_LEVEL_INTERFACE_H

#include <memory>
#include <utility>

#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/point.h"

class Board;

class LevelInterface {
    int level;

  	virtual std::unique_ptr<UnplacedBlock> getNextBlockImpl(
      Point bottomLeft) = 0;

  	virtual void actionAfterMoveImpl(Board&);

    virtual bool moveDownImpl(Board&);
    virtual bool moveLeftImpl(Board&);
    virtual bool moveRightImpl(Board&);
    virtual bool dropImpl(Board&);
    virtual bool rotateLeftImpl(Board&);
    virtual bool rotateRightImpl(Board&);

  public:
    LevelInterface(int level);
  	virtual ~LevelInterface();

    int getLevelNumber();
    // Gets the next block to be played based on the current state.
    // Assumes that it called at most once per turn.
    std::unique_ptr<UnplacedBlock> getNextBlock(Point bottomLeft);

    // Moves the current block on the board.
    bool moveDown(Board&);
    bool moveLeft(Board&);
    bool moveRight(Board&);
    bool drop(Board&);
    bool rotateLeft(Board&);
    bool rotateRight(Board&);

    void actionAfterMove(Board&);
};

#endif