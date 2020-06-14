
#include<iostream>
#include<fstream>
#include"tablica.h"
using namespace std;
int tablica::ustawRozmiar(int X, int Y)
{
	this->x = X;
	this->y = Y;
}

tablica::tablica(tablica& b)
{
	x = b.x;
	y = b.y;
	if (b.tab == nullptr)
		tab = nullptr;
	else
	{
		tab = new double*[x];
		for (size_t i = 0; i < x; i++)
			tab[i] = new double[y];
	}
}
tablica& tablica::operator=(tablica& b)
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
	x = b.x;
	y = b.y;
	if (b.tab == nullptr)
		tab = nullptr;
	else
	{
		tab = new double*[x];
		for (size_t i = 0; i < x; i++)
			tab[i] = new double[y];
	}
	
	return *this;
}
tablica::tablica(tablica&& b)
{
	x = b.x;
	y = b.y;
	tab = b.tab;
	b.x = 0;
	b.y = 0;
	b.tab = nullptr;
}
tablica& tablica::operator=(tablica&& b)
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
	x = b.x;
	y = b.y;
	tab = b.tab;
	b.x = 0;
	b.y = 0;
	b.tab = nullptr;
	
	return *this;
}
tablica::tablica(size_t x, size_t y)
{
	this->x = x;
	this->y = y;
	tab = nullptr;
	if (x == 0 || y == 0) return;
	tab = new double*[x];
	for (size_t i = 0; i < x; i++)
	{
		tab[i] = new double[y];
		for (size_t j = 0; j < y; j++)
		{
			tab[i][j] = 0;
		}
	}
}
tablica::~tablica()
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
}	

tablica tablica::utworz_tablice(size_t x, size_t y)
{
	tablica tabl;
	tabl.ustawRozmiar(x,y);
	tabl.tab= new double*[x];
	for (size_t i = 0;i<x;i++){
		tabl.tab[i]=new double [y];
	}
	return tabl;
	
}

void tablica::zmien_liczbe(tablica tabl, double liczba, size_t index_x, size_t index_y)
{
	
	if(index_x > tabl.x || index_y > tabl.y)
	{	
		cout<< "Ta komurka nie leży na tablicy";	
	}
	tabl.tab[index_x][index_y] = liczba;
}

void tablica::pokaz(tablica tabl)
{
	for (size_t i=0; i<tabl.x; i++)
	{
		for (size_t j=0; j<tabl.y; j++)
		{
			cout<<tabl.tab[i][j]<<" | ";
		}
		cout<<"\n";
	}	
}

tablica tablica::zmien_rozmiar(tablica tabl, size_t newx, size_t newy)
{
	tablica newtab=utworz_tablice(newx,newy);
	for(size_t tx=0; tx<newx; tx++)
	{
		for(size_t ty=0; ty<newy; ty++)
		{
			if(tx>=tabl.x || ty>=tabl.y)
			{
				newtab.tab[tx][ty]=0;
			}
			else
			{
				newtab.tab[tx][ty]=tabl.tab[tx][ty];	
			}
		}
	}
	delete[] tabl.tab[0];
	delete[] tabl.tab;
	return newtab;
}

tablica tablica::wczytaj(size_t &x, size_t &y)
{
	ifstream plik;
	plik.open("plik.txt");
	if(plik.good()==1)
	{
		plik >> x >> y;
		tablica tabl = utworz_tablice(x,y);
		for(size_t index_x=0; index_x < tabl.x; index_x++)
		{
			for (size_t index_y=0; index_y < tabl.y; index_y++)
			{
				plik>>tabl.tab[index_x][index_y];
			}
		return tabl; 
		}
	}
} 

tablica tablica::zapisz(tablica tabl)
{
	ofstream plik;
	plik.open("plik.txt");
	if(plik.good()==1)
	{
		plik<<tabl.x<<endl<<tabl.y<<endl;
		for(size_t index_x=0; index_x < tabl.x; index_x++)
		{
			for (size_t index_y=0; index_y < tabl.y; index_y++)
			{
				plik<<tabl.tab[index_x][index_y]<<" ";
			}
			plik<<endl;
		} 
	}	
} 
tablica tablica::sumuj_pow(tablica tabl)
{
	tablica newtab=utworz_tablice(1,tabl.y);
	for(size_t ty=0; ty<=tabl.y; ty++)
	{
		int newNumb = 0;
		for(size_t tx=0; tx<tabl.x; tx++)
		{
			 newNumb += tabl.tab[tx][ty];
		}
		newtab.tab[0][ty]= newNumb;	
		
	}
	delete[] tabl.tab;
	return newtab;
}



tablica tablica::szukaj_pow_najw(tablica tabl)
{
	tablica newtab=utworz_tablice(1,tabl.y);
	for(size_t ty=0; ty<=tabl.y; ty++)
	{
		int newNumb = tabl.tab[0][ty];
		for(size_t tx=0; tx<tabl.x; tx++)
		{
			if (newNumb < tabl.tab[tx][ty])
			{
				newNumb = tabl.tab[tx][ty];
			}
		}
		newtab.tab[0][ty]= newNumb;	
		
	}
	delete[] tabl.tab;
	return newtab;
}

tablica tablica::szukaj_pow_najm(tablica tabl)
{
	tablica newtab=utworz_tablice(1,tabl.y);
	for(size_t ty=0; ty<=tabl.y; ty++)
	{
		int newNumb = tabl.tab[0][ty];
		for(size_t tx=0; tx<tabl.x; tx++)
		{
			if (newNumb > tabl.tab[tx][ty])
			{
				newNumb = tabl.tab[tx][ty];
			}
		}
		newtab.tab[0][ty]= newNumb;	
		
	}
	delete[] tabl.tab;
	return newtab;
}

tablica tablica::szukaj_pow_srednia(tablica tabl)
{
	tablica newtab=utworz_tablice(1,tabl.y);
	for(size_t ty=0; ty<=tabl.y; ty++)
	{
		int newNumb = 0;
		for(size_t tx=0; tx<tabl.x; tx++)
		{
			 newNumb += tabl.tab[tx][ty];
		}
		newtab.tab[0][ty]= newNumb / tabl.x;	
		
	}
	delete[] tabl.tab;
	return newtab;
}


tablica tablica::sumuj_pok(tablica tabl)
{
	tablica newtab=utworz_tablice(tabl.x,1);
	for(size_t tx=0; tx<=tabl.x; tx++)
	{
		int newNumb = 0;
		for(size_t ty=0; ty<tabl.y; ty++)
		{
			 newNumb += tabl.tab[tx][ty];
		}
		newtab.tab[tx][0]= newNumb;	
		
	}
	delete[] tabl.tab;
	return newtab;
}

tablica tablica::szukaj_pok_najw(tablica tabl)
{
	tablica newtab=utworz_tablice(tabl.x,1);
	for(size_t tx=0; tx<=tabl.x; tx++)
	{
		int newNumb = tabl.tab[tx][0];
		for(size_t ty=0; ty<tabl.y; ty++)
		{
			if (newNumb < tabl.tab[tx][ty])
			{
				newNumb = tabl.tab[tx][ty];
			}
		}
		newtab.tab[tx][0]= newNumb;	
		
	}
	delete[] tabl.tab;
	return newtab;
}

tablica tablica::szukaj_pok_najm(tablica tabl)
{
	tablica newtab=utworz_tablice(tabl.x,1);
	for(size_t tx=0; tx<=tabl.x; tx++)
	{
		int newNumb = tabl.tab[tx][0];
		for(size_t ty=0; ty<tabl.y; ty++)
		{
			if (newNumb > tabl.tab[tx][ty])
			{
				newNumb = tabl.tab[tx][ty];
			}
		}
		newtab.tab[tx][0]= newNumb;	
		
	}
	delete[] tabl.tab;
	return newtab;
}

tablica tablica::szukaj_pok_srednia(tablica tabl)
{
	tablica newtab=utworz_tablice(tabl.x,1);
	for(size_t tx=0; tx<=tabl.x; tx++)
	{
		int newNumb = 0;
		for(size_t ty=0; ty<tabl.y; ty++)
		{
			 newNumb += tabl.tab[tx][ty];
		}
		newtab.tab[tx][0]= newNumb / tabl.y;	
		
	}
	delete[] tabl.tab;
	return newtab;
}
