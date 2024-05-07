#include <iostream>

bool negacja(bool p);  //funkcje zosta³y przepisane z zadania drugiego
bool koniunkcja(bool p, bool q);
bool alternatywa(bool p, bool q);
bool implikacja(bool p, bool q);
bool rownowaznosc(bool p, bool q);

using namespace std;

int main()
{
	bool p = 1, q = 1, r = 0;  //wartosci p,q i r wynikajace z zadania

	cout << "Wartosci musza wynosic 0 lub 1 i byc oddzielone spacja\nPodaj p, q i r: ";
	cin >> p >> q >> r;

	cout << "a)" << koniunkcja(p, q);  //wyniki
	cout << "\nb)" << alternatywa(p, q);
	cout << "\nc)" << koniunkcja(negacja(p), alternatywa(p, q));
	cout << "\nd)" << implikacja(koniunkcja(p, r), q);
	cout << "\ne)" << negacja(rownowaznosc(p, alternatywa(q, r)));
	cout << "\nf)" << rownowaznosc(alternatywa(implikacja(p, r), negacja(q)), implikacja(p, alternatywa(r, negacja(q))));
	cout << "\ng)" << implikacja(alternatywa(alternatywa(negacja(r), q), negacja(koniunkcja(q, r))), negacja(implikacja(q, p)));

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