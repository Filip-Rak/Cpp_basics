#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<int> kolejka;

    for(int i=0; i<2; i++)
    {
        int num;
        cout<<"Podaj "<<i+1<<" liczbe "; cin>>num;
        kolejka.push(num);
    }

    cout<<"Wynikiem mnozenia jest: "<<kolejka.front() * kolejka.back()<<endl;
    cout<<"Wynikiem dodawania jest: "<<kolejka.front() + kolejka.back()<<endl;
    cout<<"Wynikiem odejmowania jest: "<<kolejka.front() - kolejka.back()<<endl;
    cout<<"Wynikiem dzielenia jest: "<<kolejka.front() / kolejka.back()<<endl;

    cout<<"Pierwsza liczba w kolejce: "<<kolejka.front()<<endl;
    cout<<"Ostatnia liczba w kolejce: "<<kolejka.back()<<endl;
    cout<<"Wielkosc kolejki: "<<kolejka.size()<<endl;
}
