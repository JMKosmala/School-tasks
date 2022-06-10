#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>
const int w = 6;
const int k = 7;
const int G = 5;
using namespace std;

struct SPunkty
{
    double x,y;
};

void losuj_punkty (SPunkty X[][k],int wybor)
{
srand(time(0));
    if (wybor==1)
    {
    for (int i=0; i<w; i++)
        for (int j=0; j<k; j++)
            if (i==0||i==w-1||j==0||j==k-1)
                {
                X[i][j].x = (-9 + rand()%(9 - (-9) - 1));
                X[i][j].y = (-9 + rand()%(9 - (-9) - 1));
                }
            else
                {
                X[i][j].x = (-20 + rand()%(20 - (-20) - 1));
                X[i][j].y = (-20 + rand()%(20 - (-20) - 1));
                }
    }
    else
    {
    for (int i=0; i<w; i++)
        for (int j=0; j<k; j++)
            if (i==0||i==w-1||j==0||j==k-1)
                {
                X[i][j].x = (-20 + rand()%(20 - (-20) - 1));
                X[i][j].y = (-20 + rand()%(20 - (-20) - 1));
                }
            else
                {
                X[i][j].x = (-9 + rand()%(9 - (-9) - 1));
                X[i][j].y = (-9 + rand()%(9 - (-9) - 1));
                }
    }
}
void drukuj_tablice (SPunkty X[][k])
{
    for (int i=0; i<w; i++)
        {
        for (int j=0; j<k; j++)
            {
            if (X[i][j].y < -9)
                {
                cout << fixed << setw(10)<< setprecision(0) <<X[i][j].x<<","<<X[i][j].y;
                }
            else if (X[i][j].y >= -9 && X[i][j].y < 0)
                {
                cout << fixed << setw(10)<< setprecision(0)<<X[i][j].x<<","<<X[i][j].y<<" ";
                }
            else if (X[i][j].y >= 0 && X[i][j].y <= 9)
                {
                cout << fixed << setw(10)<< setprecision(0)<<X[i][j].x<<", "<<X[i][j].y<<" ";
                }
            else
                {
                cout << fixed << setw(10)<< setprecision(0)<<X[i][j].x<<", "<<X[i][j].y;
                }

            }cout<<endl;
        }
}
void zastap (SPunkty X[][k],int nr_kol, int wartosc, int &zmiany)
{
int i,j;
double suma=0,licznik=0;

    for (j=nr_kol-1;j<nr_kol;j++)
    {
        for (i=0; i<w;i++)
        {
            if (X[i][j].x > wartosc)
                {
                suma += X[i][j].x;
                licznik++;
                }
        }
    }
    for (j=nr_kol-1;j<nr_kol;j++)
        for (i=0; i<w;i++)
            {
            if (licznik!=0)
                {
                X[i][j].x=(suma/licznik);
                zmiany++;
                }
            }
}

int main()
{
int a=0;
SPunkty A[w][k], B[w][k];

losuj_punkty(A,1);
losuj_punkty(B,0);

cout<<"Tablica A"<<endl;
cout<<endl;
drukuj_tablice(A);
cout<<"\nTablica B"<<endl;
cout<<endl;
drukuj_tablice(B);

zastap (A,2,0,a);

zastap (B,4,G,a);

cout<<"\nTablica A po zmianach"<<endl;
cout<<endl;
drukuj_tablice(A);
cout<<"\nTablica B po zmianach"<<endl;
cout<<endl;
drukuj_tablice(B);

cout<<"\nliczba dokonanych zmian w obu tablicach wynosi: "<<a<<endl;

    return 0;
}
