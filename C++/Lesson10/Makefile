CXXFLAGS = -D NDEBUG -o3

main.exe : main.o rubrica.o voce.o
		g++ main.o rubrica.o voce.o -o main.exe

main.o : main.cpp rubrica.h voce.h
	g++ -c $(CXXFLAGS) main.cpp -o main.o

rubrica.o : rubrica.cpp rubrica.h voce.h
	g++ -c $(CXXFLAGS) rubrica.cpp -o rubrica.o

voce.o : voce.cpp voce.h
	g++ -c $(CXXFLAGS) voce.cpp -o voce.o


.PHONY: clean
clean:
		rm -rf *.o main.exe main2.exe
