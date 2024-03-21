#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<float> stos;

    for(int i=0; i<2; i++)
    {
        int num;
        cout<<"Podaj liczbe: "; cin>>num;
        stos.push(num);
    }

    float b = stos.top();
    stos.pop();
    float a = stos.top();

    cout<<"Wynik dodawania: "<<a + b<<endl;
    cout<<"Wynik odejmowania: "<<a - b<<endl;
    cout<<"Wynik mnozenia: "<<a * b<<endl;
    cout<<"Wynik dzielenia: "<<a / b<<endl<<endl;

    cout<<"Rozmiar stosu (1 element usuniety): "<<stos.size();
}
