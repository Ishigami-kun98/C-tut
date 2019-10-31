CXXFLAGS = -D NDEBUG -o3

main.exe : main.o dbuffer.o
		g++ main.o dbuffer.o -o main.exe

main2.exe : main2.o dbuffer.o
		g++ main2.o dbuffer.o -o main2.exe

main2.o : main2.cpp dbuffer.h
	g++ -c $(CXXFLAGS) main2.cpp -o main2.o

main.o : main.cpp dbuffer.h
	g++ -c $(CXXFLAGS) main.cpp -o main.o

dbuffer.o : dbuffer.cpp dbuffer.h
	g++ -c $(CXXFLAGS) dbuffer.cpp -o dbuffer.o



.PHONY: clean
clean:
		rm -rf *.o main.exe main2.exe
