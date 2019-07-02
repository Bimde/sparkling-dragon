#ifndef INTERFACES_HINTINTERFACE_H
#define INTERFACES_HINTINTERFACE_H

#include <memory>

class UnplacedBlock;

class HintInterface {
	virtual std::unique_ptr<UnplacedBlock> generateHintImpl(
		std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock) = 0;
  
  public:
  	virtual ~HintInterface();

  	std::unique_ptr<UnplacedBlock> generateHint(
		std::weak_ptr<Board> board, std::weak_ptr<UnplacedBlock> currentBlock);

  	static std::unique_ptr<HintInterface> createHint();
};

#endif