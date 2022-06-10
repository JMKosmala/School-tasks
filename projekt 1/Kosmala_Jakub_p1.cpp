#include <iostream>

using namespace std;

//deklaracja stalych, zmiennych, elementow listy  i zmiennych pomocniczych//
const int n =8;
struct Spogoda
{
   string miasto;
   float temperatura;
   Spogoda *next;
};

Spogoda *glowa, *aktualny=NULL, *poprzedni=NULL, *nowy;
double suma=0, srednia=0;

//deklaracja funkcji//
void drukuj(Spogoda *adres);
void lista(Spogoda *adres);
void kasuj (Spogoda *&adres);

//funkcja glowna//
int main()
{
lista(glowa);
drukuj(glowa);

//obliczanie sredniej temperatury//
aktualny=glowa;
    do
    {
        suma+=aktualny->temperatura;
        aktualny = aktualny->next;
    }
    while(aktualny!=NULL);
srednia= suma/n;
cout<<"\nSrednia temperatura wynosi: "<<srednia<<" stopni"<<endl;

//wypisanie miast z z temperatura powyzej sredniej//
cout<<"\nMiasta w ktorych temperatura jest wyzsza od sredniej: "<<endl;
aktualny=glowa;
    while(aktualny!=NULL)
    {
    if (aktualny->temperatura>srednia)
        cout<<aktualny->miasto<<", ";
    aktualny = aktualny->next;
    }

kasuj(glowa);
drukuj(glowa);
    return 0;
}


//funkcja drukujaca//
void drukuj(Spogoda *adres)
{
        adres=glowa;
        if(glowa==NULL)
            cout <<"\n\nNie mozna wydrukowac listy. Lista jest pusta";
        else
        {
            cout<<"\nPodana lista:\n\n";
            while (adres!= NULL)
            {
            cout << adres->miasto<<"\t "<<adres->temperatura<< endl;
            adres = adres->next;
            }
        }
}
//funkcja tworzaca liste i dopisujaca wpisywane dane na jej koncu//
void lista(Spogoda *adres)
{
int ile, l_poz=0;
string city;

cout << "Podaj "<<n<<" kolejnych miast oraz temperature dla nich" << endl;

    while(l_poz!=n)
    {
        cout<<"Podaj miasto: ";
        cin >> city;
        cout<<"Temperatura: ";
        cin >>ile;

        poprzedni=aktualny;
        aktualny = new Spogoda;
        aktualny -> miasto =city;
        aktualny -> temperatura =ile;
        aktualny -> next = NULL;

        if (poprzedni!= NULL)
            poprzedni ->next = aktualny;
        else
            glowa = aktualny;

        while(aktualny ->next != NULL)
        {
            aktualny = aktualny->next;
            aktualny -> next = nowy;
        }
        l_poz ++;
    }
}
//funkcja kasujaca liste//
void kasuj (Spogoda *&adres)
{
    if (adres==NULL)
        cout<<"Nie ma takiej listy.\n";
    else
    {
        while(adres!=NULL)
        {
            poprzedni=adres;
            adres=adres->next;
            delete poprzedni;
        }
    cout<<"\n\nLista zostala skasowana";
    }
}
