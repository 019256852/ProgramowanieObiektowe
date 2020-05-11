#pragma once
#include<iostream>
#include<fstream>
using namespace std;
struct tablica
{
	double** tab;
	size_t x = 0;
	size_t y = 0;
};

/** \brief Funkcja tworząca tablicę 
@param x - ilość wieszy
@param y - kolumn
*/
tablica utworz_tablice(size_t x, size_t y);

/** \brief Funkcja zmieniająca liczbę w tablicy
@param tabl - struktura tablicy
@param liczba - nowa liczba
@param index_x - wiersz w którym zostanie zmieniona liczba
@param index_y - kolumna w której zostanie zmieniona liczba
*/
void zmien_liczbe(tablica tabl, double liczba, size_t index_x, size_t index_y);

/** \brief Funkcja zmieniająca rozmiar
@param tabl - struktura tablicy
@param newx - nowa ilość wierszy 
@param newy - nowa ilość kolumn
*/
tablica zmien_rozmiar(tablica tabl, size_t newx, size_t newy);

/** \brief Funkcja pokazująca tablicę
@param tabl - struktura tablicy
*/
void pokaz(tablica tabl);

/** \brief Funkcja wczytująca tablicę z pliku
@param &x - wczytane wiersze
@param &y - wczytane kolumny
*/
tablica wczytaj(size_t &x, size_t &y);

/** \brief Funkcja zapisująca tablicę do pliku
@param tabl - struktura tablicy
*/
void zapisz(tablica tabl);

/** \brief Funkcja sumująca po kolumnach
@param tabl - struktura tablicy

*/
tablica sumuj_pok(tablica tabl);

/** \brief Funkcja sumująca po wierszach
@param tabl - struktura tablicy

*/
tablica sumuj_pow(tablica tabl);

/** \brief Funkcja szukająca największej po wierszach

*/
tablica szukaj_pow_najw(tablica tabl);

/** \brief Funkcja szukająca najmniejszej po wierszach
@param tabl - struktura tablicy

*/
tablica szukaj_pow_najm(tablica tabl);

/** \brief Funkcja szukająca sredniej po wierszach
@param tabl - struktura tablicy

*/
tablica szukaj_pow_srednia(tablica tabl);

/** \brief Funkcja szukająca największej po kolumnach

*/
tablica szukaj_pok_najw(tablica tabl);

/** \brief Funkcja szukająca najmniejszej po kolumnach
@param tabl - struktura tablicy

*/
tablica szukaj_pok_najm(tablica tabl);

/** \brief Funkcja szukająca sredniej po kolumnach
@param tabl - struktura tablicy

*/
tablica szukaj_pok_srednia(tablica tabl);


