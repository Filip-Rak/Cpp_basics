#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stos;

    for(int i=0; i<8; i++)
    {
        int liczba;

        cout<<"Liczba: "<<i+1<<endl;
        cin>>liczba;

        if(liczba!=0)
            stos.push(liczba);
        else
            --i;
    }


    for(int i=0; i<8; i++)  //Sprawdzamy czy dziala
    {
        cout<<"Liczba na miejscu: "<<8-i<<" "<<stos.top()<<endl;
        stos.pop();
    }
}
