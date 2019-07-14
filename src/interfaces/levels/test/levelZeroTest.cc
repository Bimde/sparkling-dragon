#include <iostream>
#include <memory>

#include "src/interfaces/levels/test/levelZeroTest.h"
#include "src/interfaces/point.h"
#include "src/interfaces/unplacedBlock.h"
#include "src/interfaces/levels/levelZero.h"
#include "src/testing/testMacros.h"

namespace LevelZeroTest {
bool runTest() {
	bool passedAll = true;
	std::cout << "Begin Testing LevelZero!" << std::endl;

	std::unique_ptr<LevelInterface> lvl = 
		std::make_unique<LevelZero>("src/interfaces/levels/test/level_zero_test1.txt");

	EXPECT_EQ_SETFLAG(lvl->getLevelNumber(), 0, passedAll)

	const Point point(0,0);
	const std::vector<char> expectedBlocks = {'I', 'J', 'L', 'O', 'S', 'T', 'Z'};

	for (const char expectedBlockType : expectedBlocks) {
		auto block = lvl->getNextBlock(point);

		CHECK_NOT_NULLPTR_SETFLAG_OR(block, passedAll, continue;)
		EXPECT_EQ_SETFLAG(block->getType(), expectedBlockType, passedAll)
	}
	
	// Make sure it loops again
	for (const char expectedBlockType : expectedBlocks) {
		auto block = lvl->getNextBlock(point);

		CHECK_NOT_NULLPTR_SETFLAG_OR(block, passedAll, continue;)
		EXPECT_EQ_SETFLAG(block->getType(), expectedBlockType, passedAll)
	}

	std::cout << "End Testing LevelZero! (COMPLETE)" << std::endl;
	return passedAll;
}
}  // namespace