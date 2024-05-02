#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in;
    in.open("in.txt");

    string str;
    getline(in, str);

    for(int i=str.length()-1; i>=0; i--)
        cout<<str[i];
}
