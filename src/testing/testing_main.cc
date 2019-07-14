#include <iostream>

#include "src/interfaces/levels/test/levelZeroTest.h"

int main() {
	std::cout << "Testing all" << std::endl;

	bool passedAllLvlZero = LevelZeroTest::runTest();

	std::cout << "Testing all done" << std::endl;
}