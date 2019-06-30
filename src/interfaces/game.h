#ifndef INTERFACES_GAME_H
#define INTERFACES_GAME_H

#include <vector>

#include "placedBlock.h"
#include "unplacedBlock.h"
#include "level.h"
#include "enums.h"

class Game {
    std::vector<std::vector<PlacedBlock*>> board;
    UnplacedBlock currentBlock;
    Level level;
};
#endif // INTERFACES_GAME_H