#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream in;
    in.open("in.txt", ios::in);

    string str;
    getline(in, str);

    fstream out;
    out.open("out.txt", ios::out);

    out<<str;

    in.close();
    out.close();
}
