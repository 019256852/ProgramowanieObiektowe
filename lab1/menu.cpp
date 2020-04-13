#include<iostream>
#include"tablica.h"
using namespace std;
void menu(){
int wybor;
size_t x,y;
double** tab;
program:
	cout<<"1.Utworz tablice"<<endl<<"2.Zmien rozmiar "<<endl<<"3.Zmien liczbe"<<endl<<"4.Pokaz tablice"<<endl<<"5.Wczytaj"<<endl<<"6.Zapisz"<<endl<<"7.Wylacz"<<endl;
cin>>wybor;	
if(wybor == 1)
{
cout<<"Podaj liczbe wierszy"<<endl;
cin>>x;
cout<<"Podaj liczbe kolumn"<<endl;
cin>>y;
tab=utworz_tablice(x,y);
goto program;
}
if(wybor == 2)
{
size_t newx,newy;
cout<<"Podaj liczbe wierszy"<<endl;
cin>>newx;
cout<<"Podaj liczbe kolumn"<<endl;
cin>>newy;
tab=zmien_rozmiar(tab,x , y,  newx, newy);
goto program;
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
zmien_liczbe(tab,x,y,newnumber, newx, newy);
goto program;
}
	
if(wybor == 4)
{	
pokaz(tab,x,y);
goto program;
}
	
if(wybor == 5)
{
tab=wczytaj(x,y);
goto program;
}
	
if(wybor == 6)
{
zapisz(x,y,tab);
goto program;
}
if(wybor == 7)
{		
exit(0);
goto program;
}
}


