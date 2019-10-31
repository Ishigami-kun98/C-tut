CXXFLAGS = -D NDEBUG -o3

main3.exe : main3.o dbuffer.o
	g++ main.o dbuffer.o -o main3.exe

main.exe : main.o dbuffer.o
		g++ main.o dbuffer.o -o main.exe

main2.exe : main2.o dbuffer.o
		g++ main2.o dbuffer.o -o main2.exe

main2.o : main2.cpp dbuffer.h
	g++ -c $(CXXFLAGS) main2.cpp -o main2.o

main3.o : main3.cpp dbuffer.h
	g++ -c $(CXXFLAGS) main3.cpp -o main3.o

main.o : main.cpp dbuffer.h
	g++ -c $(CXXFLAGS) main.cpp -o main.o

dbuffer.o : dbuffer.cpp dbuffer.h
	g++ -c $(CXXFLAGS) dbuffer.cpp -o dbuffer.o



.PHONY: clean
clean:
		rm -rf *.o main.exe main2.exe
