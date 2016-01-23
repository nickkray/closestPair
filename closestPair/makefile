CXX = g++ 

CXXFLAGS = -g -std=c++11 -Wall

all: closestPair

closestPair: main.o pairs.o grid.o
	${CXX} $^ -o $@
clean:
	/bin/rm -f closestPair *.o
