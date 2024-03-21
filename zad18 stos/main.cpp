#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stos;

    for(int i=0; i<5; i++)
    {
        int liczba;

        cout<<"Podaj liczbe: "<<i+1<<endl;
        cin>>liczba;

        liczba *= 2;
        liczba += 2;

        stos.push(liczba);
    }


    for(int i=0; i<5; i++)  //Sprawdzam wyniki
    {
        cout<<"Liczba na stosie: "<<stos.top()<<endl;
        stos.pop();
    }
}
