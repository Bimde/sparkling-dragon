CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I../../

BLOCKOBJECTS = block.o board.o commandInterpreter.o commands.o game.o gameState.o hintGenerator.o levelFactory.o levelInterface.o placedBlock.o point.o quadris.o quadrisState.o trie.o trieNode.o unplacedBlock.o
DEPENDS = ${BLOCKOBJECTS:.o=.d}
EXEC = quadrisProgram

${EXEC}: ${BLOCKOBJECTS}
	${CXX} ${CXXFLAGS} -c ${BLOCKOBJECTS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${BLOCKOBJECTS} ${DEPENDS} ${EXEC}