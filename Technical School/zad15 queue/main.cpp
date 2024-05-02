#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<float> kolejka;

    kolejka.push(6);
    kolejka.push(7.6);
    kolejka.push(5.9);

    for(int i=0; i<3; i++)
    {
        cout<<"Zdejmujemy z kolejki: "<<kolejka.front()<<endl;
        kolejka.pop();
        cout<<"Kolejka ma teraz "<<kolejka.size()<<" wartosci"<<endl;
    }
}
