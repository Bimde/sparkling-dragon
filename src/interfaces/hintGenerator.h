#ifndef INTERFACES_HINTGENERATOR_H
#define INTERFACES_HINTGENERATOR_H

#include <memory>

class UnplacedBlock;

class HintGenerator {
	virtual UnplacedBlock generateHintImpl(
		const Board& board, const UnplacedBlock& currentBlock) = 0;
  
  public:
  	virtual ~HintGenerator();

  	UnplacedBlock generateHint(
		const Board& board, const UnplacedBlock& currentBlock);

  	static std::unique_ptr<HintGenerator> create();
};

#endif