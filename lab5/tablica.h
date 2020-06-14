#pragma once
#include<iostream>
#include<fstream>
using namespace std;


template<class T>
class cell
{
	public:
	T data;
	static T suma(cell<T>* dane, size_t n)
	{
		T acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			acc += dane[i].data;
		delete[] dane;
		return acc;
	}
	static T min(cell<T>* dane, size_t n)
	{
		T acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data < acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static T max(cell<T>* dane, size_t n)
	{
		T acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data > acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static T srednia(cell<T>* dane, size_t n)
	{
		return suma(dane, n) / n;
	}
};
template<>
class cell<string>
{
	public:
	string data;
	static string suma(cell<string>* dane, size_t n)
	{
		string acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			acc += dane[i].data;
		delete[] dane;
		return acc;
	}
	static string min(cell<string>* dane, size_t n)
	{
		string acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data < acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static string max(cell<string>* dane, size_t n)
	{
		string acc = dane[0].data;
		for (size_t i = 1; i < n; i++)
			if (dane[i].data > acc)
				acc = dane[i].data;
		delete[] dane;
		return acc;
	}
	static string srednia(cell<string>* dane, size_t n)
	{
		return "N/A";
	}
};
template<class T>
class tablica
{	
	private:
	
	size_t x = 0;
	size_t y = 0;
	cell<T> tab = NULL;

	public:
	
	
	tablica();
	tablica(tablica& b);
	tablica& operator=(tablica& b);
	tablica(tablica&& b);
	tablica& operator=(tablica&& b);
	tablica(size_t x, size_t y);
	~tablica();

	/** \brief Funkcja tworząca tablicę 
	@param x - ilość wieszy
	@param y - kolumn
	*/
	T utworz_tablice(size_t x, size_t y);
	
	/** \brief Funkcja zmieniająca liczbę w tablicy
	@param tabl - struktura tablicy
	@param liczba - nowa liczba
	@param index_x - wiersz w którym zostanie zmieniona liczba
	@param index_y - kolumna w której zostanie zmieniona liczba
	*/
	void zmien_liczbe(T liczba, size_t index_x, size_t index_y);

	/** \brief Funkcja zmieniająca rozmiar
	@param tabl - struktura tablicy
	@param newx - nowa ilość wierszy 
	@param newy - nowa ilość kolumn
	*/
	T zmien_rozmiar(size_t newx, size_t newy);

	/** \brief Funkcja pokazująca tablicę
	@param tabl - struktura tablicy
	*/
	void pokaz();
	
	/** \brief Funkcja wczytująca tablicę z pliku
	@param &x - wczytane wiersze
	@param &y - wczytane kolumny
	*/
	T wczytaj(string s);
	
	/** \brief Funkcja zapisująca tablicę do pliku
	@param tabl - struktura tablicy
	*/
	T zapisz(string s);
	
	/** \brief Funkcja sumująca po kolumnach
	@param tabl - struktura tablicy
	
	*/
	T sumuj_pok();
	
	/** \brief Funkcja sumująca po wierszach
	@param tabl - struktura tablicy
	
	*/
	T sumuj_pow();
	
	/** \brief Funkcja szukająca największej po wierszach
	
	*/
	T szukaj_pow_najw();
	
	/** \brief Funkcja szukająca najmniejszej po wierszach
	@param tabl - struktura tablicy
	
	*/
	T szukaj_pow_najm();
	
	/** \brief Funkcja szukająca sredniej po wierszach
	@param tabl - struktura tablicy
	
	*/
	T szukaj_pow_srednia();
	
	/** \brief Funkcja szukająca największej po kolumnach
	
	*/
	T szukaj_pok_najw();
	
	/** \brief Funkcja szukająca najmniejszej po kolumnach
	@param tabl - struktura tablicy
	
	*/
	T szukaj_pok_najm();
	
	/** \brief Funkcja szukająca sredniej po kolumnach
	@param tabl - struktura tablicy
	
	*/
	T szukaj_pok_srednia();
	};


template<class T>
tablica<T>::tablica(tablica& b)
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
template<class T>
tablica<T>& tablica<T>::operator=(tablica& b)
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
template<class T>
tablica<T>::tablica(tablica&& b)
{
	x = b.x;
	y = b.y;
	tab = b.tab;
	b.x = 0;
	b.y = 0;
	b.tab = nullptr;
}
template<class T>
tablica<T>& tablica<T>::operator=(tablica&& b)
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
template<class T>
tablica<T>::tablica(size_t x, size_t y)
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
template<class T>
tablica<T>::~tablica()
{
	if (tab != nullptr)
		for (size_t i = 0; i < x; i++)
			delete[] tab[i];
	delete[] tab;
}	



template<class T>
void tablica<T>::zmien_liczbe(T liczba, size_t index_x, size_t index_y)
{
	
	if(index_x > x || index_y > y)
	{	
		cout<< "Ta komurka nie leży na tablicy";	
	}
	tab[index_x][index_y] = liczba;
}
template<class T>
void tablica<T>::pokaz()
{
	for (size_t i=0; i<x; i++)
	{
		for (size_t j=0; j<y; j++)
		{
			cout<<tab[i][j]<<" | ";
		}
		cout<<"\n";
	}	
}
template<class T>
tablica<T>::zmien_rozmiar(size_t newx, size_t newy)
{
	tablica newtab=utworz_tablice(newx,newy);
	for(size_t tx=0; tx<newx; tx++)
	{
		for(size_t ty=0; ty<newy; ty++)
		{
			if(tx>=x || ty>=y)
			{
				newtab.tab[tx][ty]=0;
			}
			else
			{
				newtab.tab[tx][ty]=tab[tx][ty];	
			}
		}
	}
	
	delete[] tab;
	return newtab;
}
template<class T>
tablica<T>::wczytaj(string s)
{
	ifstream plik;
	plik.open(s);
	size_t x;
	size_t y;
	if(plik.good()==1)
	{
		plik >> x >> y;
		utworz_tablice(x,y);
		for(size_t index_x=0; index_x < x; index_x++)
		{
			for (size_t index_y=0; index_y < y; index_y++)
			{
				plik>>tab[index_x][index_y];
			}
		return tabl; 
		}
	}
} 
template<class T>
tablica<T>::zapisz(string s)
{
	ofstream plik;
	plik.open(s);
	if(plik.good()==1)
	{
		plik<<x<<endl<<y<<endl;
		for(size_t index_x=0; index_x < x; index_x++)
		{
			for (size_t index_y=0; index_y < y; index_y++)
			{
				plik<<tab[index_x][index_y]<<" ";
			}
			plik<<endl;
		} 
	}	
} 
template<class T>
tablica<T>::sumuj_pow()
{
	tablica newtab=utworz_tablice(1,y);
	for(size_t ty=0; ty<=y; ty++)
	{
		int newNumb = 0;
		for(size_t tx=0; tx<x; tx++)
		{
			 newNumb += tab[tx][ty];
		}
		newtab.tab[0][ty]= newNumb;	
		
	}
	delete[] tab;
	return newtab;
}


template<class T>
tablica<T>::szukaj_pow_najw()
{
	tablica newtab=utworz_tablice(1,y);
	for(size_t ty=0; ty<=y; ty++)
	{
		int newNumb = tab[0][ty];
		for(size_t tx=0; tx<x; tx++)
		{
			if (newNumb < tab[tx][ty])
			{
				newNumb = tab[tx][ty];
			}
		}
		newtab.tab[0][ty]= newNumb;	
		
	}
	delete[] tab;
	return newtab;
}
template<class T>
tablica<T>::szukaj_pow_najm()
{
	tablica newtab=utworz_tablice(1,y);
	for(size_t ty=0; ty<=y; ty++)
	{
		int newNumb = tab[0][ty];
		for(size_t tx=0; tx<x; tx++)
		{
			if (newNumb > tab[tx][ty])
			{
				newNumb = tab[tx][ty];
			}
		}
		newtab.tab[0][ty]= newNumb;	
		
	}
	delete[] tab;
	return newtab;
}
template<class T>
tablica<T>::szukaj_pow_srednia()
{
	tablica newtab=utworz_tablice(1,y);
	for(size_t ty=0; ty<=y; ty++)
	{
		int newNumb = 0;
		for(size_t tx=0; tx<x; tx++)
		{
			 newNumb += tab[tx][ty];
		}
		newtab.tab[0][ty]= newNumb / x;	
		
	}
	delete[] tab;
	return newtab;
}

template<class T>
tablica<T>::sumuj_pok()
{
	tablica newtab=utworz_tablice(tabl.x,1);
	for(size_t tx=0; tx<=x; tx++)
	{
		int newNumb = 0;
		for(size_t ty=0; ty<tabl.y; ty++)
		{
			 newNumb += tabl.tab[tx][ty];
		}
		newtab.tab[tx][0]= newNumb;	
		
	}
	delete[] tab;
	return newtab;
}
template<class T>
tablica<T>::szukaj_pok_najw()
{
	tablica newtab=utworz_tablice(x,1);
	for(size_t tx=0; tx<=x; tx++)
	{
		int newNumb = tabl.tab[tx][0];
		for(size_t ty=0; ty<y; ty++)
		{
			if (newNumb < tab[tx][ty])
			{
				newNumb = ab[tx][ty];
			}
		}
		tab[tx][0]= newNumb;	
		
	}
	delete[] tab;
	return newtab;
}
template<class T>
tablica<T>::szukaj_pok_najm()
{
	tablica newtab=utworz_tablice(tabl.x,1);
	for(size_t tx=0; tx<=x; tx++)
	{
		int newNumb = tabl.tab[tx][0];
		for(size_t ty=0; ty<y; ty++)
		{
			if (newNumb > tab[tx][ty])
			{
				newNumb = tab[tx][ty];
			}
		}
		newtab.tab[tx][0]= newNumb;	
		
	}
	delete[] tab;
	return newtab;
}
template<class T>
tablica<T>::szukaj_pok_srednia()
{
	tablica newtab=utworz_tablice(x,1);
	for(size_t tx=0; tx<=x; tx++)
	{
		int newNumb = 0;
		for(size_t ty=0; ty<y; ty++)
		{
			 newNumb += tab[tx][ty];
		}
		newtab.tab[tx][0]= newNumb / y;	
		
	}
	delete[] tab;
	return newtab;
}

