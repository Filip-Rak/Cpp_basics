#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stos;

    stos.push(5);
    stos.push(10);
    stos.push(12);
    stos.push(14);
    stos.push(6);
    stos.push(7);
    stos.push(3);
    stos.push(1);
    stos.push(8);
    stos.push(11);


    cout<<"Wartosc szczytowego elementu: "<<stos.top()<<endl<<endl;

    while(!stos.empty())
    {
        stos.pop();
    }

    cout<<"Wielkosc stosu po usunieciu elementow: "<<stos.size();
}
