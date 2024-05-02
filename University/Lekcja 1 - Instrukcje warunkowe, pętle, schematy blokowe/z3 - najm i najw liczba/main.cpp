#include <iostream>

int main()
{
	float min, max, num;

	std::cout << "1. Liczba: ";
	std::cin >> num;

	max = min = num;  //Uznanie pierwszej liczba za max i min

	for (int i = 2; i <= 5; i++)  //petla wykonuje sie dla pozostalych 4 liczb
	{
		std::cout << i << ". Liczba: ";
		std::cin >> num;

		if (num < min)  //Sprawdzamy czy liczba jest mniejsza/wieksza od naszych zmiennych, jezeli tak to ja do nich wpisujemy
			min = num;

		else if (num > max)
			max = num;
	}

	std::cout << "Najwieksza: " << max << " Najmniejsza: " << min << " Roznica: " << max - min << "\n";

	return 0;
}