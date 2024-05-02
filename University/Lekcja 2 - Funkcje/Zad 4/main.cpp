#include <iostream>
#include <windows.h>

int main()
{
	srand(time(NULL)); //ustawia punkt startu dla liczb losowych

	for (int i = 0; i < 6; i++)
	{
		std::cout << (rand() % 49) + 1 << " "; //wylosuj liczbe od 1-49 i wypisz
		Sleep(1000);  //Zatrzymaj program na sekunde
	}

	return 0;
}