vector: Funkcijos.o Uzduotis.o Studentas.o
	g++ Funkcijos.o Uzduotis.o Studentas.o -o vector -O2

Funkcijos.o: Funkcijos.cpp
	g++ -c Funkcijos.cpp

Uzduotis.o: Uzduotis.cpp
	g++ -c Uzduotis.cpp

Studentas.o: Studentas.cpp
	g++ -c Studentas.cpp

clean:
	del *.o *.exe vector 
