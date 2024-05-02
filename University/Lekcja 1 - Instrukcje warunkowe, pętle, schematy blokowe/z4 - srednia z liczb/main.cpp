#include <iostream>

int main()
{
	std::cout << "Podaj ilosc liczb: ";

	int n;
	std::cin >> n;  //ilosc liczb

	float sum = 0;
	for (int i = 0; i < n; i++)  //petla wykona sie dla kazdej liczby
	{
		std::cout << "Podaj liczbe " << i + 1 << ": ";

		float a;
		std::cin >> a;
		sum += a;  //liczba jest dodawana do sumy
	}

	std::cout << "\nSrednia z liczb: " << sum / n << "\n";

	for (int i = 0; i < sum / n; i++) //ilosc zer zaokraglli sie do gory
		std::cout << 0;

	return 0;
}