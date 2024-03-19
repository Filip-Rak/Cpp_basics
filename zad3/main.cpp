#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream plik;
    plik.open("zadanie3.txt");

    for(int i=0; i<=30; i++)
        plik<<i<<endl;


    plik<<"\n\n\n";


    for(int i=2; i<(5*10)+2; i+=5)
        plik<<i<<endl;

    plik.close();
}
