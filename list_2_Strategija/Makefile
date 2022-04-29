list: Funkcijos.o Uzduotis.o
	g++ Funkcijos.o Uzduotis.o -o list -O3

Funkcijos.o: Funkcijos.cpp
	g++ -c Funkcijos.cpp

Uzduotis.o: Uzduotis.cpp
	g++ -c Uzduotis.cpp

clean:
	del *.o *.exe list 
