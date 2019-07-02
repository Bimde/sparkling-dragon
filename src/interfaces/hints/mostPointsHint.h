#ifndef INTERFACES_HINTS_MOSTPOINTSHINT_H
#define INTERFACES_HINTS_MOSTPOINTSHINT_H

#include <memory>

#include "hintInterface.h"

class MostPointsHint : public HintInterface {
	std::unique_ptr<UnplacedBlock> generateHintImpl(
		std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock) 
		override;
};

#endif