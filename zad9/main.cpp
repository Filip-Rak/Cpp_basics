#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stos;

    while(stos.size() < 3)  //do 3 liczb
    {
        int num;
        cout<<"Podaj liczbe inna niz 5: "; cin>>num;

        if(num != 5)
            stos.push(num);
        else
            cout<<"Podales zla liczbe: "<<endl;
    }


    cout<<endl<<"Rozmiar stosu to: "<<stos.size()<<endl;

    while(!stos.empty())
    {
        cout<<"Liczba na stosie: "<<stos.top()<<endl;
        stos.pop();
    }

    cout<<"Rozmiar stosu po usunieciu liczb: "<<stos.size();
}
