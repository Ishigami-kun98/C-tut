CXXFLAGS = -D NDEBUG -o3
main.exe : main.o dbuffer.o
		g++ main.o dbuffer.o

main.o : main.cpp dbuffer.h
	g++ -c $(CXXFLAGS) main.cpp -o main.o

dbuffer.o : dbuffer.cpp dbuffer.h
	g++ -c $(CXXFLAGS) dbuffer.cpp -o dbuffer.o



.PHONY: clean
clean:
		rm -rf *.o *.exe
