#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;

int main()
{
    queue<int> kolejka;

    for(int i=0; i<7; i++)
    {
        int num;
        cout<<"Podaj liczbe numer "<<i+1<<": "; cin>>num;
        kolejka.push(num);
    }

    system("cls");

    while(!kolejka.empty())
    {
                kolejka.pop();
        cout<<"Usuwamy liczbe na poczatku kolejki, wielkosc kolejki to: "<<kolejka.size()<<endl<<endl;
    }
}
