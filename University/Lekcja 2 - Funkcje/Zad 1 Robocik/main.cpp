#include <iostream>

int get_input(std::string s, int arrow);

int main()
{
	int n;
	std::cout << "Ilosc ruchow robota: ";
	std::cin >> n;

	int x = 0, y = 0;
	int direction = 0;

	for (int i = 0; i < n; i++)  //wykonuje sie dla kazdego ruchu
	{
		system("cls");
		std::cout << "(" << x << ", " << y << ") ";  //wypisz pozycje

		switch (direction++)  //4 kierunki numerowane od 0-3
		{

		case 0:
			y += get_input("polnoc", 24);
			break;
		case 1:
			x += get_input("wschod", 26);
			break;
		case 2:
			y -= get_input("poludnie", 25);
			break;
		case 3:
			x -= get_input("zachod", 17);
			break;
		}

		direction %= 4;  //zeruje kierunek, gdy jest wiekszy niz 3
	}

	system("cls");
	std::cout << "(" << x << ", " << y << ") Robot zakonczyl swoja podroz\n";

	return 0;
}


int get_input(std::string s, int arrow) //wypisuje kierunek robota oraz zwraca nastp. odleglosc
{
	std::cout << "Kerunek robota to " << s << " " << char(arrow) << " - podaj odleglosc: ";

	int inp;
	std::cin >> inp;

	return inp;
}