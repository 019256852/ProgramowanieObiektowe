#include<iostream>
#include"tablica.h"
using namespace std;
void menu()
{
	int wybor;
	size_t x,y;
	tablica tabl;
	while(1)
	{
		cout<<"1.Utworz tablice"<<endl<<"2.Zmien rozmiar "<<endl<<"3.Zmien 	liczbe"<<endl<<"4.Pokaz tablice"<<endl<<"5.Wczytaj"<<endl<<"6.Zapisz"<<endl<<"7.Sumuj po kolumnach"<<endl<<"8.Sumuj po wierszach"<<endl<<"9.Szukaj największej po wierszach"<<endl<<"10.Szukaj najmniejszej po wierszach"<<endl<<"11.Szukaj sredniej po wierszach"<<endl<<"12.Szukaj najwiekszej po kolumnach"<<endl<<"13.Szukaj najmniejszej po kolumnach"<<endl<<"14.Szukaj sredniej po kolumnach"<<endl<<"15.Wylacz"<<endl;
cin>>wybor;	

		if(wybor == 1)
		{
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>x;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>y;
			tabl = tabl.utworz_tablice(x,y);
		}

		if(wybor == 2)
		{
			size_t newx,newy;
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>newx;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>newy;
			tabl = tabl.zmien_rozmiar(tabl,  newx, newy);
		}

		if(wybor == 3)
		{
			size_t newx, newy;
			double newnumber;
			cout<<"Podaj wiersz: ";
			cin>>newx;
			cout<<"Podaj kolumne: ";
			cin>>newy;
			cout<<"Podaj liczbe: ";
			cin>>newnumber;
			tabl.zmien_liczbe(tabl,newnumber, newx, newy);
		}

		if(wybor == 4)
		{	
			tabl.pokaz(tabl);
		}
		if(wybor == 5)
		{
			tabl = tabl.wczytaj(x,y);
		}
	
		if(wybor == 6)
		{
			tabl = tabl.zapisz(tabl);
		}
		if(wybor == 7)
		{
			tabl = tabl.sumuj_pok(tabl);
		}
		if(wybor == 8)
		{
			tabl = tabl.sumuj_pow(tabl);
		}
		if(wybor == 9)
		{
			tabl = tabl.szukaj_pow_najw(tabl);
		}
		if(wybor == 10)
		{
			tabl = tabl.szukaj_pow_najm(tabl);
		}
		if(wybor == 11)
		{
			tabl = tabl.szukaj_pow_srednia(tabl);
		}
		if(wybor == 12)
		{
			tabl = tabl.szukaj_pok_najw(tabl);
		}
		if(wybor == 13)
		{
			tabl = tabl.szukaj_pok_najm(tabl);
		}
		if(wybor == 14)
		{
			tabl = tabl.szukaj_pok_srednia(tabl);
		}

		if(wybor == 15)
		{		
			exit(0);
		}
	}
}


