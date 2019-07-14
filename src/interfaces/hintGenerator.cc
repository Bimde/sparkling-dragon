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
	UnplacedBlock b = currentBlock
	return b.moveDown();
}
}  // namespace

UnplacedBlock HintGenerator::generateHint(
	const Board& board, const UnplacedBlock& currentBlock) {
	generateHintImpl(board, currentBlock);
}

std::unique_ptr<HintGenerator> HintGenerator::create() {
	return std::make_unique<HintGeneratorImpl>();
}