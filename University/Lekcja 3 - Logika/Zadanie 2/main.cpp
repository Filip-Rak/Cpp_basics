#include <iostream>

bool negacja(bool p);  
bool koniunkcja(bool p, bool q);
bool alternatywa(bool p, bool q);
bool implikacja(bool p, bool q);
bool rownowaznosc(bool p, bool q);

int main()
{
	int a, b;

	do  
	{
		std::cout << "Podaj a i b oddzielone znakiem spacji: ";
		std::cin >> a >> b;
		system("cls");

	} while ((a != 0 && a != 1) || (b != 0 && b != 1)); //upewnia sie, ze wartosci z wejscia naleza do przedzialu 0-1

	bool p = a, q = b;  //zapisuje wartosci z wejscia jako bool

	std::cout << "p = " << p << ", q = " << q;  //wypisuje wszystkie operacje z polecenia
	std::cout << "\nNegacja p: " << negacja(p);
	std::cout << "\nNegacja q: " << negacja(q);
	std::cout << "\nKoniunkcja p i q: " << koniunkcja(p, q);
	std::cout << "\nAlternatywa p i q: " << alternatywa(p, q);
	std::cout << "\nImplikacja p i q: " << implikacja(p, q);
	std::cout << "\nRownowaznosc p i q: " << rownowaznosc(p, q) << "\n";

	return 0;
}

bool negacja(bool p)
{
	return !p;
}

bool koniunkcja(bool p, bool q)
{
	if (p && q)
		return true;

	return false;
}

bool alternatywa(bool p, bool q)
{
	if (p || q)
		return true;

	return 0;
}

bool implikacja(bool p, bool q)
{
	if ((p && q) || (!p && !q) || (!p && q))
		return true;

	return false;
}

bool rownowaznosc(bool p, bool q)
{
	if (p == q)
		return true;

	return false;
}