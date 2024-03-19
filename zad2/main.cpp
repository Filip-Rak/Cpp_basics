#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream plik;
    int liczba;

    plik.open("zadanie2.txt");

    cout<<"Podaj liczbe: "; cin>>liczba;


    for(int i=1; i<=liczba; i++)
    {
        if(liczba%i==0)
            plik<<i<<endl;
    }

    plik.close();
}
