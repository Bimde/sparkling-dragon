#include <iostream>
#include <memory>

#include "src/interfaces/point.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/levels/levelZero.h"

int main() {
	std::unique_ptr<LevelInterface> lvl = 
		std::make_unique<LevelZero>("src/interfaces/levels/test/level_zero_test1.txt");

	if (lvl->getLevelNumber() != 0) {
		std::cout << "Expected level number: 0 --- Got level number: " 
			<< lvl->getLevelNumber() << std::endl;
	}

	const Point point(0,0);
	const std::vector<char> expectedBlocks = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

	for (const char expectedBlockType : expectedBlocks) {
		auto block = lvl->getNextBlock(point);

		if (block == nullptr) {
			std::cout << "Expected block: " << expectedBlockType 
				<< " --- Got block : nullptr " << std::endl;
		} else if (block->getType() != expectedBlockType) {
			std::cout << "Expected block: " << expectedBlockType 
				<< " --- Got block : " << block->getType() << std::endl;
		}
	}

	std::cout << "Testing completed!" << std::endl;
	return 0;
}