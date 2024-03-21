#include <iostream>
#include <queue>

using namespace std;

int main()
{
    queue<string> kolejka;

    for(int i=0; i<=5; i++)
    {
        kolejka.push("kolejka");
    }

    while(!kolejka.empty())
    {
        kolejka.pop();
        cout<<kolejka.front()<<endl;
    }
}
