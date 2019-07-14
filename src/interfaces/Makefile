CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I../../

OBJECTS = block.o board.o commandInterpreter.o game.o hintGenerator.o levelFactory.o levelInterface.o placedBlock.o quadris.o quadrisState.o trie.o trieNode.o unplacedBlock.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = quadris.out

all: ${EXEC} copy_to_bin

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -c ${OBJECTS}

-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	cp *.o ../../../bin
	# cp quadris.out ../../../out

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}