#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream plik;
    string im, nazw;

    plik.open("zadanie2.txt");

    cout<<"Podaj imie: "; cin>>im;
    plik<<"prosze podac swoje imie: "<<im<<endl;

    cout<<"Podaj Nazwisko: "; cin>>nazw;
    plik<<"Prosze podac swoje nazwisko: "<<nazw<<endl;;

    plik<<"Nazywasz sie: "<<im + " " + nazw;

    plik.close();
}
