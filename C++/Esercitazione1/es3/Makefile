main.exe : roman.o main.o
	g++ roman.o main.o -o main.exe


main.o : main.cpp
	g++ -c main.cpp


roman.o : roman.cpp
	g++ -c roman.cpp

.PHONY: clean
clean:
		rm -rf *.o main.exe
