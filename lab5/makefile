program: main.o tablica.o menu.o
	g++ -o program main.o menu.o
main.o: main.cpp menu.h
	g++ -c main.cpp
menu.o: menu.cpp menu.h tablica.h
	g++ -c menu.cpp

