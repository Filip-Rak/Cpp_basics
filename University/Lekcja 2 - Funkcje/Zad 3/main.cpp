#include <iostream>

int main()
{
	srand(time(NULL));
	int random = (rand() % 100) + 1; //losuje liczbe z zakresu 1 do 100

	int trials = 0;  //proby

	while (true)
	{
		int guess;
		trials++;

		std::cout << "Proba nr. " << trials << " Podaj liczbe: ";
		std::cin >> guess;
		system("cls");

		if (guess == random) //ify sprawdzaja czy nasza liczba sie zgadza, jest za mala albo za duza
		{
			std::cout << "Zgadles w " << trials << "-ej probie\n";
			break;
		}
		if (guess < random)
			std::cout << "Za malo\n";
		else
			std::cout << "Za duzo\n";
	}

	return 0;
}