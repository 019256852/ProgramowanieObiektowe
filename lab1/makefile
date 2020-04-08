program: main.o tablica.o menu.o
	g++ -o program main.o tablica.o menu.o
main.o: main.cpp menu.h
	g++ -c main.cpp
tablica.o: tablica.cpp tablica.h
	g++ -c tablica.cpp
menu.o: menu.cpp menu.h tablica.h
	g++ -c menu.cpp

