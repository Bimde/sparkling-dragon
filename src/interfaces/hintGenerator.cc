#include <memory>

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

HintGenerator::~HintGenerator() {}

UnplacedBlock HintGenerator::generateHint(
	const Board& board, const UnplacedBlock& currentBlock) {
	return generateHintImpl(board, currentBlock);
}

std::unique_ptr<HintGenerator> HintGenerator::create() {
	return std::make_unique<HintGeneratorImpl>();
}