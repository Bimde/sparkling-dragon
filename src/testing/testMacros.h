#ifndef TESTING_TESTMACROS_H
#define TESTING_TESTMACROS_H

#include <iostream>

#define OUTPUT_EQ_MSG(result, expected) \
 	std::cout << "EQ failed: Expected: " << expected \
 		<< " --- Got: " << result << std::endl

#define OUTPUT_NEQ_MSG(result, expected) \
 	std::cout << "NEQ failed: Expected and Got: " << expected

#define EXPECT_EQ_SETFLAG(result, expected, flag) \
	if (result != expected) { \
		flag = false; \
		OUTPUT_EQ_MSG(result, expected); \
	}

#define EXPECT_EQ(result, expected) \
	if (result != expected) { \
		OUTPUT_EQ_MSG(result, expected); \
	}

#define EXPECT_NEQ_SETFLAG(result, expected, flag) \
	if (result == expected) { \
		flag = false; \
		OUTPUT_NEQ_MSG(result, expected); \
	}

#define EXPECT_NEQ(result, expected) \
	if (result == expected) { \
		OUTPUT_NEQ_MSG(result, expected); \
	}

// Checks nullptr and if it is nullptr, runs ... (where ... is code)
#define CHECK_NOT_NULLPTR_OR(ptr, ...) \
	if (ptr == nullptr) { \
		std::cout << "Check not Nullptr failed." << std::endl; \
		#__VA_ARGS__ \
	}

#define CHECK_NOT_NULLPTR_SETFLAG_OR(ptr, flag, ...) \
	if (ptr == nullptr) { \
		flag = false; \
		std::cout << "Check not Nullptr failed." << std::endl; \
		#__VA_ARGS__ \
	}

#endif