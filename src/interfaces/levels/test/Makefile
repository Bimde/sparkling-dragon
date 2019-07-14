CXX = g++
CXXFLAGS = -std=c++14 -Wall -I../../../../

all: list

list: *.cc
	@for FILE in $^; do \
		${CXX} ${CXXFLAGS} -c $${FILE} -o ../../../../bin/$${FILE%.cc}.o; \
	done