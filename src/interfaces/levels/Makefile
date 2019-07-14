CXX = g++
CXXFLAGS = -std=c++14 -Wall -I../../../

OBJECTS = blockGenerator.o levelZero.o levelOne.o levelTwo.o levelThree.o levelFour.o levelFourFile.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = levels.out

all: ${EXEC} copy_to_bin rm_o_d

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -c ${OBJECTS}
	
-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	cp *.o ../../../bin
	# cp levels.out ../../../out

rm_o_d: SHELL := /bin/bash
rm_o_d: 
	rm -f *.o *.d

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}