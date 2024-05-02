#include <iostream>

int main()
{
	std::cout << "Podaj dwie liczby calkowite oddzielone znakiem spacji: ";

	int a, b;
	std::cin >> a >> b;

	if (a > b)  //aranzuje liczby tak aby zmienna a byla ta mniejsza
	{
		int c = b;
		b = a;
		a = c;
	}

	std::cout << "\nliczby z podanego przedzialu:\n";
	
	int sum = 0;
	for (int i = a; i <=b; i++)  //wypisuje przedzial
	{
		std::cout << i << " ";

		if (i % 2 == 0)  //oraz zlicza liczby parzyste w przedziale
			sum += i;
	}

	std::cout << "\nSuma liczb parzystych w przedziale: " << sum << "\n";

	return 0;
}