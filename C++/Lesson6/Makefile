main.exe : dbuffer.o main.o
	g++ dbuffer.o main.o

dbuffer.o: dbuffer.cpp dbuffer.h
	g++ -c dbuffer.cpp

main.o : main.cpp dbuffer.h
	g++ -c main.cpp

.PHONY : clean
clean:
	rm -rf *.o main.exe
