#include <iostream>
#include <windows.h>

using namespace std;

const int limit = 50;
float weight[limit], value[limit], amount[limit];

int maxMass, propAmount;

int main()
{
    cout<<"Ile wagi moze pomiescic plecak?\n"; cin>>maxMass;
    cout<<"Ile przdmiotow chcesz wlozyc?\n"; cin>>propAmount;

    for(int i=0; i<propAmount; i++)
    {
        cout<<"Przedmiot nr: "<<i+1<<endl;
        cout<<"Wartosc: "; cin>>value[i];
        cout<<"Waga: "; cin>>weight[i];
        amount[i] = 0;
    }

    float rate[limit];
    for(int i=0; i<propAmount; i++)
    {
        rate[i] = value[i] / weight[i];
    }


    int mass = maxMass;
    while(mass>0)
    {
        float bestRate = 0; //Upewnij sie ze to dobry placeholder
        int bestRateID = -1;

        for(int j=0; j<propAmount; j++)
        {
            if(weight[j]<=mass)
            {
                float rate = value[j] / weight[j];

                if(rate>=bestRate)
                {
                    bestRate = rate;
                    bestRateID = j;
                }
            }
        }

        if(bestRateID == -1)  //Brak przedmiotow ktore sie zmieszcza
             break;  //Zakoncz liczenie

        amount[bestRateID]++;
        mass -= weight[bestRateID];
    }

    system("cls");
    for(int i=0; i<propAmount; i++)
    {
        cout<<"------------------------"<<endl;
        cout<<"Nr przedmiotu: "<<i+1<<endl;
        cout<<"Ilosc: "<<amount[i]<<endl;
        cout<<"Waga: "<<weight[i]<<endl;
        cout<<"Wartosc: "<<value[i]<<endl;
    }
}
