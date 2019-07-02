#ifndef INTERFACES_LEVELS_LEVELFOUR_H
#define INTERFACES_LEVELS_LEVELFOUR_H

#include "levelInterface.h"

class LevelFour : public LevelInterface {
  public:
  	LevelFour();
  	UnplacedBlock getNextBlock() override;

  	void moveDown(Board&) override;
    void moveLeft(Board&) override;
    void moveRight(Board&) override;
    void drop(Board&) override;
};

#endif