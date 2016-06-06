
Flags = -Wreturn-type -pedantic -pedantic-errors -Wundef -std=c++11
CPP = g++


main : Makefile   main.o rectangle.o circle.o triangle.o
	$(CPP) $(Flags) -o main   main.o rectangle.o circle.o triangle.o

main.o : Makefile   main.cpp   rectangle.h triangle.h circle.h
	$(CPP) -c $(Flags) main.cpp -o  main.o


rectangle.o : Makefile   rectangle.cpp   rectangle.h	surf.h
	$(CPP) -c $(Flags) rectangle.cpp -o  rectangle.o

triangle.o : Makefile   triangle.cpp   triangle.h	surf.h
	$(CPP) -c $(Flags) triangle.cpp -o  triangle.o

circle.o : Makefile   circle.cpp   circle.h	surf.h
	$(CPP) -c $(Flags) circle.cpp -o  circle.o
