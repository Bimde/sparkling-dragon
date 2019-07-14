#include <memory>
#include <iostream>

#include "src/interfaces/hintGenerator.h"
#include "src/interfaces/board.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
class HintGeneratorImpl : public HintGenerator {
	UnplacedBlock generateHintImpl(
		const Board& board, const UnplacedBlock& currentBlock)
		override;
};

UnplacedBlock HintGeneratorImpl::generateHintImpl(
	const Board& board, const UnplacedBlock& currentBlock) {
	// TODO 
	UnplacedBlock b = currentBlock;
	b.moveDown();
	return b;
}
}  // namespace

HintGenerator::HintGenerator() {
	std::cout << "Hint gen ctor" << std::endl;
}

HintGenerator::~HintGenerator() {}

UnplacedBlock HintGenerator::generateHint(
	const Board& board, const UnplacedBlock& currentBlock) {
	return generateHintImpl(board, currentBlock);
}

std::unique_ptr<HintGenerator> HintGenerator::create() {
	std::cout << "Hint generator create" << std::endl;
	return std::make_unique<HintGeneratorImpl>();
}