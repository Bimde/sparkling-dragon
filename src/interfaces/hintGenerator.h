#ifndef INTERFACES_HINTGENERATOR_H
#define INTERFACES_HINTGENERATOR_H

#include <memory>

class UnplacedBlock;

class HintGenerator {
	virtual std::unique_ptr<UnplacedBlock> generateHintImpl(
		std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock) = 0;
  
  public:
  	virtual ~HintGenerator();

  	std::unique_ptr<UnplacedBlock> generateHint(
		std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock);

  	static std::unique_ptr<HintGenerator> create();
};

#endif