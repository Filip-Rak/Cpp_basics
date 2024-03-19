#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream inpA, inpB;
    float a, b, c, d, e, f;
    inpA.open("dane3.txt");
    inpB.open("dane4.txt");

    inpA>>a;
    inpA>>b;
    inpA>>c;
    inpA>>d;
    inpB>>e;
    inpB>>f;

    float wynik;
    wynik = a + b + c + d + e + f;
    cout<<"Wynik dodawania to: "<<wynik<<endl;

    wynik = a - b - c - d - e - f;
    cout<<"Wynik odejmowania to: "<<wynik<<endl;

    wynik = a * b * c * d * e * f;
    cout<<"Wynik mnozenia to: "<<wynik<<endl;

    inpA.close();
    inpB.close();
}
