CXX = g++
CXXFLAGS = -std=c++14 -Wall -I../../../

OBJECTS = blockGenerator.o levelZero.o levelOne.o levelTwo.o levelThree.o levelFour.o levelFourFile.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = levels.out

all: ${EXEC} copy_to_bin

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -c ${OBJECTS}
	
-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	cp *.o ../../../bin
	# cp levels.out ../../../out

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}