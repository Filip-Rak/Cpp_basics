#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int verts, edges; 

	cout << "Liczba wierzcholkow: ";
	cin >> verts;
	
	cout << "Liczba krawedzi: ";
	cin >> edges;

	vector<string> relations;

	for (int i = 0; i < edges; i++)  //zbiera pary wierzcholkow i zapisuje do tablicy
	{
		system("cls");
		cout << "Krawedz podajemy wzorem wierzcholek0-wierzcholek1, krawedz bedzie skierowana w kierunku wierzcholek1, numeracja od 0\nPrzyklad wejscia: 0-1\n////\n";
		cout << "Krawedz: " << i + 1 << "\n";
		cout << "Podaj pary wierzcholkow odzdzielajac je znakiem enter: ";

		string input;
		cin >> input;

		relations.push_back(input);
	}

	int** matrix = new int*[verts];  //tworzy tablice wskaznikow
	for (int i = 0; i < verts; i++) 
	{
		matrix[i] = new int[verts];  //w miejscach wskaznikow tworzy tablice. Efektem jest macierz kwadratowa

		for (int j = 0; j < verts; j++)  //wypelnia macierz zerami
			matrix[i][j] = 0;
	}



	for (int i = 0; i < relations.size(); i++)  //wykonuje sie dla kazdej pary wierzcholkow
	{
		int start, finish, divider = 0;
		string temp;

		for (int j = 0; j < relations[i].length(); j++)  //wyciaga pierwszy wierzcholek z podanej pary (zmienna start)
		{
			if (relations[i][j] == '-')
			{
				divider = j;
				break;
			}
			else
				temp += relations[i][j];
		}

		start = stoi(temp);  //i konwertuje go na liczbe
		temp.clear();

		for (int j = divider + 1; j < relations[i].length(); j++)  //wyciaga drugi wierzcholek z pary (zmienna finish)
		{
			if (relations[i][j] == '-')
				break;
			else
				temp += relations[i][j];
		}

		finish = stoi(temp);

		matrix[start][finish]++;  //zapisuje polaczenia w macierzy
		//matrix[finish][start]++;  
		//c) odkomentowanie powyzszej linijki sprawi, ze wynik bedzie dla grafu niekierowanego
	}



	system("cls");  //czysci ekran i wypisuje macierz
	for (int i = 0; i < verts; i++)
	{
		for (int j = 0; j < verts; j++)
			cout << matrix[i][j] << " ";

		cout << "\n";
	}

	return 0;
}