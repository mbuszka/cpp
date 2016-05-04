# Automatically generated Makefile
# Makefile-generator programmed by Hans de Nivelle, 2002


Flags = -Wall -Wextra -pedantic -std=c++11 -Wno-unused-parameter -g -std=c++11
CPP = g++


main : Makefile   main.o ../List5/tree.o matching.o rewrite_system.o
	$(CPP) $(Flags) -o main   main.o ../List5/tree.o matching.o rewrite_system.o

main.o : Makefile   main.cpp   rewrite_system.h ../List5/tree.h matching.h
	$(CPP) -c $(Flags) main.cpp -o  main.o


../List5/tree.o : Makefile   ../List5/tree.cpp   ../List5/tree.h
	$(CPP) -c $(Flags) ../List5/tree.cpp -o  ../List5/tree.o


matching.o : Makefile   matching.cpp   matching.h ../List5/tree.h
	$(CPP) -c $(Flags) matching.cpp -o  matching.o

rewrite_system.o : Makefile ../List5/tree.h rewrite_system.h rewrite_system.cpp
	$(CPP) -c $(Flags) rewrite_system.cpp -o  rewrite_system.o
