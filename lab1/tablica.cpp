#include<iostream>
#include<fstream>
using namespace std;
struct tablica
{
	double** tab;
	size_t x = 0;
	size_t y = 0;
};

tablica utworz_tablice(size_t x, size_t y)
{
	tablica tabl;
	tabl.x = x;
	tabl.y = y;
	tabl.tab= new double*[x];
	for (size_t i = 0;i<x;i++){
		tabl.tab[i]=new double [y];
	}
	return tabl;
	
}

void zmien_liczbe(tablica tabl, double liczba, size_t index_x, size_t index_y)
{
	tabl.tab[index_x][index_y] = liczba;
}

void pokaz(tablica tabl)
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

tablica zmien_rozmiar(tablica tabl, size_t newx, size_t newy)
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
	delete[] tabl.tab;
	return newtab;
}

tablica wczytaj(size_t &x, size_t &y)
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

void zapisz(tablica tabl)
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
tablica sumuj_pow(tablica tabl)
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



tablica szukaj_pow_najw(tablica tabl)
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

tablica szukaj_pow_najm(tablica tabl)
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

tablica szukaj_pow_srednia(tablica tabl)
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


tablica sumuj_pok(tablica tabl)
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

tablica szukaj_pok_najw(tablica tabl)
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

tablica szukaj_pok_najm(tablica tabl)
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

tablica szukaj_pok_srednia(tablica tabl)
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
