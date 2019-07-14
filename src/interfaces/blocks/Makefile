CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I../../../

BLOCKOBJECTS = iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o starBlock.o tBlock.o zBlock.o
DEPENDS = ${BLOCKOBJECTS:.o=.d}
EXEC = blocks

${EXEC}: ${BLOCKOBJECTS}
	${CXX} ${CXXFLAGS} -c ${BLOCKOBJECTS}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${BLOCKOBJECTS} ${DEPENDS} ${EXEC}