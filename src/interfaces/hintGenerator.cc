#include <memory>

#include "src/interfaces/hintGenerator.h"
#include "src/interfaces/board.h"
#include "src/interfaces/unplacedBlock.h"

namespace {
class HintGeneratorImpl : public HintGenerator {
	std::unique_ptr<UnplacedBlock> generateHintImpl(
		std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock)
		override;
};

std::unique_ptr<UnplacedBlock> HintGeneratorImpl::generateHintImpl(
	std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock) {
	// TODO
}
}  // namespace

std::unique_ptr<UnplacedBlock> HintGenerator::generateHint(
	std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock) {
	generateHintImpl(board, currentBlock);
}

std::unique_ptr<HintGenerator> HintGenerator::create() {
	return new HintGeneratorImpl;
}