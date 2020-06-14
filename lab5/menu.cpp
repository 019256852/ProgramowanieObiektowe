#include<iostream>
#include"tablica.h"
using namespace std;
void menu()
{
	int wybor;
	size_t x,y;
	tablica<my_type> tabl;
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
			tabl = tablica<my_type>(x,y);
		}

		if(wybor == 2)
		{
			size_t newx,newy;
			cout<<"Podaj liczbe wierszy"<<endl;
			cin>>newx;
			cout<<"Podaj liczbe kolumn"<<endl;
			cin>>newy;
			tabl = tabl.zmien_rozmiar(newx, newy);
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
			tabl.zmien_liczbe(newnumber, newx, newy);
		}

		if(wybor == 4)
		{	
			tabl.pokaz();
		}
		if(wybor == 5)
		{
			tabl = tabl.wczytaj(s);
		}
	
		if(wybor == 6)
		{
			tabl = tabl.zapisz(s);
		}
		if(wybor == 7)
		{
			tabl = tabl.sumuj_pok();
		}
		if(wybor == 8)
		{
			tabl = tabl.sumuj_pow();
		}
		if(wybor == 9)
		{
			tabl = tabl.szukaj_pow_najw();
		}
		if(wybor == 10)
		{
			tabl = tabl.szukaj_pow_najm();
		}
		if(wybor == 11)
		{
			tabl = tabl.szukaj_pow_srednia();
		}
		if(wybor == 12)
		{
			tabl = tabl.szukaj_pok_najw();
		}
		if(wybor == 13)
		{
			tabl = tabl.szukaj_pok_najm();
		}
		if(wybor == 14)
		{
			tabl = tabl.szukaj_pok_srednia();
		}

		if(wybor == 15)
		{		
			exit(0);
		}
	}
}


