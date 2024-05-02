#include <iostream>

int main()
{
	std::cout << "Podaj rok: ";

	int r;
	std::cin >> r;


	if ((r % 4 == 0 && r % 100 != 0) || r % 400 == 0)
		std::cout << "jest to rok przestepny";
	else
		std::cout << "nie jest to rok przestepny";

	return 0;
}