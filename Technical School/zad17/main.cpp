#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> stos;

    for(int i=0; i<10; i++)
        stos.push(i);

    for(int i=10; i>2; i--)
        stos.pop();

        cout<<stos.size();
}
