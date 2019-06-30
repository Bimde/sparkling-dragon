#ifndef INTERFACES_LEVEL_H
#define INTERFACES_LEVEL_H

#include "unplacedBlock.h"

class Level {
  public:
    UnplacedBlock getNextBlock();
};

#endif // INTERFACES_LEVEL_H