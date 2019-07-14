SRC_DIR = ../../../

CXX = g++-5
CXXFLAGS = -g -std=c++17 -Wall -MMD -I${SRC_DIR}
EXEC = test
OBJECTS = levelZero.o list.o iter.o node.o
DEPENDS = ${OBJECTS:.o=.d}

deps: 

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}