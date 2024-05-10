#include <iostream>
#include <string>
#include <fstream>

#define alphabet 26	 

using namespace std;

string caesar_cipher(string input, int offset)  //szyf cezara
{
	string output = "";  //prechowuje wynik

	for (int i = 0; i < input.length(); i++)
	{
		int start = 65;
		if (int(input[i]) >= 97)  //przy pomocy ASCII sprawdza czy litera jest duza czy mala
			start = 97;
		
		int newPos = ((int(input[i]) - start + offset) % alphabet) + start;  //oblicza numer ASCII po przesunieciu
		output += char(newPos);
	}

	return output;
}

string bacon_cipher(string input) //szyfr bakonski 
{
	const string CODE[alphabet] = { "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab", 
	"ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab",
	"babba", "babbb", "bbaaa", "bbaab"};  //oznaczenie kazdej litery w szyfrze

	string output = "";  //przechowuje wynik

	for (int i = 0; i < input.length(); i++)
	{
		int start = 65;
		if (int(input[i]) >= 97)  //sprawdza czy litera wejsciowa jest duza czy mala
			start = 97;
		
		int newSign = int(input[i] - start);  
		output += CODE[newSign];  //znajduje zakodowany odpowiednik litery
	}

	return output;
}

string bacon_decipher(string input)  //dzesyforwanie szyfru bekonskiego
{
	const string CODE[alphabet] = { "aaaaa", "aaaab", "aaaba", "aaabb", "aabaa", "aabab", "aabba", "aabbb", "abaaa", "abaab",
	"ababa", "ababb", "abbaa", "abbab", "abbba", "abbbb", "baaaa", "baaab", "baaba", "baabb", "babaa", "babab",
	"babba", "babbb", "bbaaa", "bbaab" };
	const int piece_length = 5;

	string output = "";  //przechowuje wynik

	for (int i = 0; i < input.length(); i += piece_length)
	{
		string fragment = input.substr(i, piece_length); //dzieli wejscie na 5 literowe fragmenty

		for (int j = 0; j < alphabet; j++)  //szuka odpowiednika dragmentu w tablicy
		{
			if (fragment == CODE[j])  
			{
				output += char(97 + j);  //na podstawie pozycji w tablicy i tabeli ASCII przydziela mala litere w alfabecie
				break;
			}
		}
	}

	return output;
}

int main()
{
	int service, cipher;

	do
	{
		cout << "1. Szyfrowanie\n2. Deszyfrowanie\n";
		cin >> service;

		system("cls");

	} while (service > 2 || service < 1);  //petla wykonuje sie, dopoki nie dostanie oczekiwanej wartosci
							
	do
	{
		cout << "1. Szyfr Cezara\n2. Szyfr Bakonski\n";
		cin >> cipher;

		system("cls");
	} while (cipher > 2 || cipher < 1);


	if (service == 1) //if decyduje czy uzytkownik chce zaszyfrowac czy zddszyfrowac plik. 1 = szyfrowanie
	{

		cout << "Tekst (tylko litery): ";

		string text;
		cin >> text;

		string output;
		switch (cipher)  //sprawdza ktory rodzaj szyfrowania wybral uzytkownik
		{
			//szyfr cezara
			case 1: 
				cout << "Wartosc przesuiecia: ";
				int n;
				cin >> n;
				output = caesar_cipher(text, n);
				break;

			//szyfr bakonski
			case 2: 
				output = bacon_cipher(text);
				break;
		}

		system("cls");
		cout << "Do jakiego pliku zapisac? ";  //zapisywanie do pliku
		
		string fname;  
		cin >> fname;

		std::fstream file(fname, std::ios::out);  //nadpisuje plik, ktorego nazwa zostala podana. Jezeli nie istnieje - tworzy go
		
		file << output << "\n";
		file.close();
	}
	else //deszyfrowanie
	{
		cout << "Plik do deszyfrowania: ";

		string fname;
		cin >> fname;

		fstream file(fname, ios::in);
		string buffer;
		string fullTxt = "";

		while (getline(file, buffer))  //spisuje linjka po linijce zawartosc pliku do zmiennej
			fullTxt += buffer;

		file.close();

		string output;
		switch (cipher)  //sprawdza rodzaj deszyfrowania
		{
		case 1:  //cezara
			cout << "Przesuniecie: ";

			int n;
			cin >> n;

			output = caesar_cipher(fullTxt, alphabet - (n % alphabet)); //przesuwa szyfr o pozostale litery z alafabetu. W efekcie wraca on do pierowotnej formy
			break;
		case 2:  //bakonski
			output = bacon_decipher(fullTxt);
			break;
		}

		system("cls");
		cout << output << "\n";
	}

	return 0;
}