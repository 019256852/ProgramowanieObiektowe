#include<iostream>
#include<fstream>
using namespace std;
double** utworz_tablice(size_t x, size_t y)
{
	double** tab= new double*[x];
	for (size_t i = 0;i<x;i++)
		tab[i]=new double [y];
	return tab;
	
}

void zmien_liczbe(double* tab, size_t x,size_t y, double liczba, size_t index_x, size_t index_y)
{
tab[index_x][index_y] = liczba;
}

void pokaz(double** tab, size_t x, size_t y)
{
for (size_t i=0; i<x; i++)
{
for (size_t j=0; j<y; j++)
	cout<<tab[i][j]<<" | ";
cout<<"\n";
}	
}

double** zmien_rozmiar(double** tab, size_t &x,size_t &y, size_t newx, size_t newy)
{
double** newtab=utworz_tablice(newx,newy);
for(size_t tx=0; tx<newx; tx++)
{
for(size_t ty=0; ty<newy; ty++){
	if(tx>=x || ty>=y)
		newtab[tx][ty]=0;
	else
		newtab[tx][ty]=tab[tx][ty];	
		
		}
	}
	delete[] tab;
	x=newx;
	y=newy;
	return newtab;
}

double** wczytaj(size_t &x, size_t &y)
{
ifstream plik;
plik.open("plik.txt");
if(plik.good()==1){
plik>>x>>y;
double** tab = utworz_tablice(x,y);
for(size_t index_x=0; index_x < x; index_x++)
	for (size_t index_y=0; index_y < y; index_y++)
		plik>>tab[index_x][index_y];
return tab; 
}
} 

void zapisz(size_t x, size_t y, double* tab)
{
	ofstream plik;
	plik.open("plik.txt");
	if(plik.good()==1){
	plik<<x<<endl<<y<<endl;
		for(size_t index_x=0; index_x < x; index_x++){
			for (size_t index_y=0; index_y < y; index_y++)
				plik<<tab[index_x][index_y]<<" ";
			plik<<endl;
		} 
	}
	
} 

