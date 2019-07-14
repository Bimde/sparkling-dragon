#include <iostream>

#include "src/interfaces/levels/test/levelZeroTest.h"
#include "src/ui/test/basic_ui_test.h"

int main() {
	std::cout << "Testing all" << std::endl;

	bool passedAllLvlZero = LevelZeroTest::runTest();
	bool passBasicUITest = BasicUITest::runTests();

	std::cout << "Testing all done" << std::endl;
}