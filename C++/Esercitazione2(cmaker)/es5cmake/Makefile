main.exe : point.o rectangle.o main.o
	g++ -o point.o rectangle.o main.o -o main.exe

main.o : main.cpp include/rectangle.h include/point.h
	g++ -I./include -c main.cpp

point.o : ./src/point.cpp
	g++ -I./include -c ./src/point.cpp

rectangle.o : ./src/rectangle.cpp
	g++ -I./include -c ./src/rectangle.cpp

.PHONY : clean
clean:
	rm -rf *.o main.exe
