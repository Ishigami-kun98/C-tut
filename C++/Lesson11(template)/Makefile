CXXFLAGS = -D NDEBUG -O3
#CXXFLAGS = 

main.exe: main.o 
	g++ main.o -o main.exe

main.o: main.cpp dbufferT.h
	g++ -c $(CXXFLAGS) main.cpp -o main.o


.PHONY: clean
clean:
	rm *.o *.exe

