#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream plik;
    plik.open("dane.txt");

    ofstream wynik;
    wynik.open("wyniki.txt");

    for(int i=0; i<6; i++)
    {
        for(int i=0; i<2; i++)
        {
            int a=0, b=0;

            plik>>a;
            plik>>b;

            if(a*b>20 && a*b<40)
            {
                wynik<<a*b<<endl;
            }

        }
    }

    plik.close();
    wynik.close();
}
