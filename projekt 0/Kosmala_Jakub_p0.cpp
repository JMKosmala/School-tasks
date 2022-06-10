#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <fstream>
#include <vector>
using namespace std;

const int n=100;
const int G=70;
int i=0;

struct STab
{
    char x;
    int y;
};

void drukuj (STab X[n])
    {
    if(n>20)
    for (i=n-20;i<n;i++)
        cout <<i<<". "<<X[i].x<<" "<<X[i].y<<endl;
    else
    for (i=0;i<n;i++)
        cout <<i<<". "<<X[i].x<<" "<<X[i].y<<endl;
    }

void losuj1 (STab X[n])
    {
    for (i=0;i<n;i++)
         {
        X[i].x =('A' + rand()%('Z'+1-'A'));
        X[i].y = rand()%(G+1);
         };
    }

void losuj2 (STab X[n])
{
    while (i<n)
    {
    X[i].x =('A' + rand()%('Z'+1-'A'));
    X[i].y = rand()%(G+1);
    i++;
    losuj2 (X);
    };
}


int main()
{
srand(time(0));
STab A[n], B[n];
int wybor;

cout<<"Witam. Jaki rodzaj tablicy chcialbys wydrukowac?:\n\n1.Tablice statyczna wypelniona w sposob iteracyjny\n";
cout<<"2.Tablice statyczna wypelniona w sposob rekurencyjny\n3.Tablice dynamiczna wypelniona w sposob iteracyjny\n";
cout<<"Twoj wybor: "; cin>>wybor;

switch (wybor)
{
    case 1:
        {
        cout<<"\nTablica A\n";
        losuj1 (A);
        drukuj (A);
        cout<<"\nRozmiar tablicy A wynosi: "<<n<<endl;
        cout<<"Zamjmuje ona "<<sizeof (A)<<" bajtow pamieci"<<endl;
        }
        break;

    case 2:
        {
        cout<<"\nTablica B\n";
        losuj2 (B);
        drukuj (B);
        cout<<"\nRozmiar tablicy B wynosi: "<<n<<endl;
        cout<<"Zamjmuje ona "<<sizeof (B)<<" bajtow pamieci"<<endl;
        }
        break;

    case 3:
        {
        STab *D;
        int k=1;
        cout <<"Ile elementow zawierac ma tablica D?\n";
        cin >> k;
        cout << "k= "<< k <<"\n\nTablica 3\n"<<endl;

        D = new STab[k];
            {
            for (i=0;i<k;i++)
                {
                D[i].x =('A' + rand()%('Z'+1-'A'));
                D[i].y = rand()%(G+1);
                };
            }
        if (k>20)
            for (i=k-20;i<k;i++)
            cout <<i<<". "<<D[i].x<<" "<<D[i].y<<endl;
        else
            for (i=0;i<k;i++)
            cout <<i<<". "<<D[i].x<<" "<<D[i].y<<endl;

        cout<<"\nRozmiar tablicy D wynosi: "<<k<<endl;
        cout<<"Zamjmuje ona "<<sizeof(STab)*k<<" bajtow pamieci"<<endl;


        delete []D;
        }
        break;

    default:
        cout<<"Nie ma takiej opcji!";
        break;


}
    return 0;
}
