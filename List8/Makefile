Flags = -Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter -g -std=c++11
CPP = g++

main : Makefile main.o
	$(CPP) $(Flags) -o main main.o

main.o : Makefile main.cpp
	$(CPP) -c $(Flags) main.cpp -o  main.o
