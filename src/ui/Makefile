CXX = g++
CXXFLAGS = -std=c++14 -Wall -MMD -I../../

OBJECTS = display.o observer.o subject.o window.o
DEPENDS = ${OBJECTS:.o=.d}

all: compile copy_to_bin

compile: ${OBJECTS}
	${CXX} ${CXXFLAGS} -c ${OBJECTS}

-include ${DEPENDS}

copy_to_bin: SHELL := /bin/bash
copy_to_bin:
	mv *.o ../../bin

.PHONY: clean

clean:
	rm ${OBJECTS} ${DEPENDS} ${EXEC}