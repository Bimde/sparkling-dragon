CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I../../../../

OBJECTS = testing_main.o
DEPENDS = ${OBJECTS:.o=.d}
EXEC = test.out

all: ${EXEC} copy_to_bin rm_o_d

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} -c ${OBJECTS}

-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	cp *.o ../../../../bin
	# cp test.out ../../../../out

rm_o_d: SHELL := /bin/bash
rm_o_d: 
	rm -f *.o *.d

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}