#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<float> kolejka;

    kolejka.push(6.0);
    kolejka.push(7.6);
    kolejka.push(5.9);

    cout<<"Wielkosc kolejki to: "<<kolejka.size()<<endl<<endl;

    while(!kolejka.empty())
    {
        kolejka.pop();
        cout<<"Po zmniejszeniu kolejki jej wielkosc to: "<<kolejka.size()<<endl;
    }
}
