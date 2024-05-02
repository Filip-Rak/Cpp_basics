#include <iostream>

int LiczbyPitagorejskie(int a, int b, int c)
{
	if ((a * a) + (b * b) == (c * c))
		return 1;
	
	return 0;
}

int main()
{
	std::cout << "Podaj trzy liczby oddzielone znakami spacji: ";
	
	int a, b, c;
	std::cin >> a >> b >> c;

	std::cout << "Funkcja LiczbyPitagorejskie() zwrocila wartosc: " << LiczbyPitagorejskie(a, b, c) << "\n";

	return 0;
}