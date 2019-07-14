CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I../../

OBJECTS = block.o board.o commandInterpreter.o game.o hintGenerator.o levelFactory.o levelInterface.o quadris.o trie.o trieNode.o unplacedBlock.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = quadris.out

all: ${EXEC} copy_to_bin rm_o_d

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -c ${OBJECTS}

-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	cp *.o ../../bin
	# cp quadris.out ../../../out

rm_o_d: SHELL := /bin/bash
rm_o_d:
	rm -f *.o *.d

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}