#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <iomanip>

using namespace std;

const int w=5;
const int k=6;
const int r=10;
const int d=20;
const int g=80;

//funkcja losujaca wartosci do tablicy z podanego zakresu

void losuj_tablice(double X[][k],int a, int b)
{
    srand(time(0));
    for (int i=0; i<w; i++)
        for (int j=0; j<k; j++)
            X[i][j] = (a + rand()%(b - a - 1));

}
//funkcja drukujaca tablice o okreslona iloscia miejsc po przecinku

void drukuj_tablice (double X[][k],int przecinek)
{
    for (int i=0; i<w; i++)
        {
        for (int j=0; j<k; j++)
        cout << fixed << setprecision(przecinek) << setw(10)<<X[i][j];
        cout << endl;
        }
}
//funkcja odwracajaca tablice w wierszach w ktorych suma jest mniejsza od podanej wartosci

int odwroc_tablice (double X[][k],double wartosc)
    {
double schowek=1.0;
int l_wier=0;

    for (int i=0;i<w;i++)
        {
        double suma=0;
        for (int j=0; j<k; j++)
            suma=suma+X[i][j];
            if (suma < wartosc)
                {
                for (int j=0;j<(k/2);j++)
                {
                schowek = X[i][k-1-j];
                X[i][k-1-j]=X[i][j];
                X[i][j] = schowek;
                }
                l_wier++;
                }
        }
return l_wier;
}

int main()
{
double liczba;
double A[w][k], B[w][k];

cout<< "Drukuje tablice A\n\n";
losuj_tablice(A, -r, r);
drukuj_tablice(A, 1);

cout<< "\nDrukuje tablice B\n\n";
losuj_tablice (B, d, g);
drukuj_tablice (B, 2);

cout<<"\nDrukuje tablice A w taki sposob, ze w wierszach w ktorych suma ";
cout<<"\nelementow jest mniejsza od 0, odwrocona zostanie kolejnosc elementow\n\n";
odwroc_tablice (A,0);
drukuj_tablice (A,1);

cout<<"\nLiczba odwroconych wierszy to: "<<odwroc_tablice(A,0)<<endl;
cout<<"\nPodaj wartosc do ktorej porownane zostana wiersze w tablicy B: ";
cin>>liczba;

cout<<"\nDrukuje tablice B w taki sposob, ze w wierszach w ktorych suma elementow ";
cout<<"\njest mniejsza od podanej wartosci, odwrocona zostanie kolejnosc elementow\n\n";
odwroc_tablice (B,liczba);
drukuj_tablice (B, 2);

cout<<"\nLiczba odwroconych wierszy w tablicy to: "<<odwroc_tablice(B,liczba)<<endl<<endl;

if (odwroc_tablice(A,0)>odwroc_tablice(B,liczba))
    cout<<"Wiecej wierszy odwrocono w tablicy A"<<endl;
else if (odwroc_tablice(A,0)<odwroc_tablice(B,liczba))
    cout<<"Wiecej wierszy odwrocono w tablicy B"<<endl;
else
    cout<<"W obu wierszach odwrocono taka sama ilosc wierszy"<<endl;
    return 0;
}
