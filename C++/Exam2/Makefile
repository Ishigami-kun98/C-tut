main.exe : main.o
	g++ main.o -o main.exe

main.o : main.cpp iris.h
	g++ -c main.cpp -o main.o

.PHONY: clean
clean:
	rm -rf *.o main.exe
