#include<iostream>
#include<fstream>
using namespace std;
double** utworz_tablice(size_t x, size_t y);
void zmien_liczbe(double* tab, size_t x,size_t y, double liczba, size_t index_x, size_t index_y);
double** zmien_rozmiar(double* tab, size_t &x,size_t &y, size_t newx, size_t newy);
void pokaz(double* tab, size_t x, size_t y);
double** wczytaj(size_t &x, size_t &y);
void zapisz(size_t x, size_t y, double* tab);
