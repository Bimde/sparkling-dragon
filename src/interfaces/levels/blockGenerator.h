#ifndef INTERFACES_LEVELS_BLOCK_GENERATOR_H
#define INTERFACES_LEVELS_BLOCK_GENERATOR_H

#include <memory>

#include "interfaces/point.h"
#include "interfaces/unplacedBlock.h"

std::unique_ptr<UnplacedBlock> createLetterBlock(
	char type, int score, Point bottomLeft);

#endif