#include <iostream>
#include <queue>
#include <windows.h>

using namespace std;

int main()
{
    queue<string> kolejka;

    string str;

    cout<<"Podaj nazwisko: "; cin>>str;

    kolejka.push(str);

    cout<<"Podaj imie: "; cin>>str;

    kolejka.push(str);

    cout<<"Podaj miejscoowsc: "; cin>>str;

    kolejka.push(str);

    cout<<"Podaj ulice: "; cin>>str;

    kolejka.push(str);

    cout<<"Podaj wojewodztwo: "; cin>>str;

    kolejka.push(str);


    system("cls");
    cout<<"Wyniki:"<<endl;

    for(int i=0; i<5; i++)
    {
        cout<<kolejka.front()<<endl;
        kolejka.pop();
    }

}
