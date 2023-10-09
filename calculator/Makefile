.PHONY: all debug release clean

all: debug release 

debug: main-dbg

main-dbg: main.cpp
	g++  -O0 main.cpp -o main-dbg -Wall

release: main

main: main.cpp
	g++ -O2 main.cpp -o main -DNDEBUG -Wall

clean:
	rm -rf *.o main
	rm -rf *.o main-dbg
