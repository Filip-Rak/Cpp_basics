#include <iostream>

const int NUMS = 100;

int wyraz_ciagu(int a, int r, int n)
{
	return a + (n * r);
}

int main()
{
	int a, r;

	std::cout << "Podaj pierwszy wyraz i roznice, oddziel znakiem spacji: ";
	std::cin >> a >> r;

	int wyrazy[NUMS][2];

	for (int i = 0; i < NUMS; i++)
	{
		wyrazy[i][0] = i + 1;
		wyrazy[i][1] = wyraz_ciagu(a, r, i);
	}

	for (int i = 0; i < NUMS; i++)
		std::cout << wyrazy[i][0] << " " << wyrazy[i][1] << "\n";

	return 0;
}