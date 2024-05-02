#include <iostream>

double pa_to_tor(double pa) //Funkcje liczace
{
	return pa * 0.0075;
}

double pa_to_psi(double pa)
{
	return pa * (145.038 * pow(10, -6));
}

double pa_to_bar(double pa)
{
	return pa * pow(10, -5);
}

int main()
{
	double pa;
	std::cout << "Podaj ilosc Pa : ";
	std::cin >> pa;

	int selection;
	std::cout << "Przelicz na: 1-bar, 2-tor, 3-psi: ";
	std::cin >> selection;


	switch (selection)  //Wybor wlasciwej funkcji i wypisanie wyniku
	{
	case 1:
		std::cout << pa << " Pa = " << pa_to_bar(pa) << " bar \n";
		break;
	case 2:
		std::cout << pa << " Pa = " << pa_to_tor(pa) << " tor \n";
		break;
	case 3:
		std::cout << pa << " Pa = " << pa_to_psi(pa) << " psi \n";
		break;

	default:
		std::cout << "Opcja " << selection << " jest niedostepna\n";
	}

	return 0;
}