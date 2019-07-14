CXX = g++
CXXFLAGS = -std=c++14 -Wall -I../../../

BLOCKOBJECTS = iBlock.o jBlock.o lBlock.o oBlock.o sBlock.o starBlock.o tBlock.o zBlock.o
DEPENDS = ${BLOCKOBJECTS:.o=.d}
EXEC = blocks.out

all: ${EXEC} copy_to_bin

${EXEC}: ${BLOCKOBJECTS}
	${CXX} ${CXXFLAGS} -c ${BLOCKOBJECTS}
	
-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	cp *.o ../../../bin
	# cp blocks.out ../../../bin

.PHONY: clean

clean:
	rm ${BLOCKOBJECTS} ${DEPENDS} ${EXEC}