#include <iostream>
#include <string> 

using namespace std;

string reverse_str(string s);  //deklaracje funkcji. Definicje znajduja sie ponizej funkcji main()
string dec_to_bin(int dec);
string dec_to_hex(int dec);
int bin_to_dec(long long int bin);
string bin_to_hex(long long int bin);
string oct_to_bin(long long int oct);

int main()
{
	cout << "Wybierz funkcje do konwersji:\n1)Dzie - Bin\n2)Dzie - Szesn\n3)Bin - Dzie\n4)Bin - Szesn\n5)Octa - Bin\nPodaj numer: ";
	int selection;
	cin >> selection;

	cout << "Podaj liczbe do konwersji: ";
	long long int num;
	cin >> num;

	cout << "Wynik to: ";
	switch (selection)  //switch decyduje o tym jaka funkcja zostanie uzyta do konwersji
	{
	case 1:
		cout << dec_to_bin(num);
		break;
	case 2:
		cout << dec_to_hex(num);
		break;
	case 3:
		cout << bin_to_dec(num);
		break;
	case 4:
		cout << bin_to_hex(num);
		break;
	case 5:
		cout << oct_to_bin(num);
		break;
	default:
		cout << "Brak wyniku - Niepoprawnie wybrana funkcja";
	}
	cout << "\n";

	return 0;
}

string reverse_str(string s)  //funkcja odwraca ciagi znakow
{
	string reversed = "";

	for (int i = s.length() - 1; i >= 0; i--)
		reversed += s[i];

	return reversed;
}

string dec_to_bin(int dec)  //dziesietny na binarny
{
	string bin = "";  //przechowuje wynik

	while (dec > 0)  //odpowiednik binarny obliczamy wilokrotnie dzielac liczbe dziesietna przez 2 i zapisujac jej reszte z dzielenia
	{
		if (dec % 2 == 1)
			bin += '1';
		else
			bin += '0';

		dec /= 2;
	}


	return reverse_str(bin);  //wynik jest odbiciem lustrzanym, musi zostac odwrocony przed zwroceniem
}

string dec_to_hex(int dec)  //dziesietny na heksodecymalny. Zasada dzialania jest dokladnie tak sama jak powyzej
{
	string hex = "";

	while (dec > 0)
	{
		int digit = dec % 16;  
		if (digit > 9)	//Jedynym wyjatkiem jest to, ze jezeli reszta z dzielenia wyjdzie wiksza niz 9
			hex += char(65 - 10 + digit);  //to przy pomocy tablicy ASCII zmieniamy ja na litere w alfabecie
		else
			hex += to_string(digit);

		dec /= 16;
	}

	return reverse_str(hex);
}

int bin_to_dec(long long int bin)  //binarny na dziesietny
{
	int dec = 0;
	int exponent = 0;

	while (bin > 0)  //Podnosimy 2 do coraz wiekszych poteg, poczwszy od zera
	{
		dec += pow(2, exponent++) * (bin % 10);  //Wynik potegowania jest mnozony przez cyfre z liczby binarnej
		bin /= 10;  //dzialanie powtarzamy dla kazdej cyfry binarnej, poczawszy od ostatniej
	}

	return dec;
}


string bin_to_hex(long long int bin) //Binarny na heksodecymalny. Najprostrzym sposobem jest uzycie naszych wczesniejszych funkcji
{
	int dec = bin_to_dec(bin);  //najpierw konwerujemy binarny na dziesietny
	string hex = dec_to_hex(dec);  //potem dziesietny na heksodecymalny

	return hex;
}

string oct_to_bin(long long int oct) //Oktalny na binarny
{
	string bin = "";

	while (oct > 0)  
	{
		int digit = oct % 10;  //lapiemy ostatnia cyfre w liczbie oktalnej
		string piece = "000";  //wydzielamy trzy cyfry binarne dla jednej oktalnej

		for (int i = 0; i < piece.length(); i++)  //petla idzie od lewej do prawej
		{
			int to_power = pow(2, piece.length() - 1 - i);  //sprawdzamy jaka wartosc miala by cyfra w systemie binarnym jezeli byla by jedynka
			
			if (digit >= to_power)  //jezeli cyfra z systemu oktalnego ma taka sama wartosc lub wieksza niz ta z systemu binarnego
			{
				digit -= to_power;  //to redukujemy cyfre oktalna o wartosc cyfry binarnej
				piece[i] = '1';  //i podmieniamy cyfre binarna na 1
			}
		}

		bin += reverse_str(piece);  //w tej metodzie ostatni fragment zostaje zapisany jako pierwszy, odrwacamy jego zawartosc, aby pozniej moc owdrocic caly wynik

		oct /= 10; //dzielimy liczbe oktalna przez 10 aby pozbyc sie ostatniej cyfry
	}

	bin = reverse_str(bin); //po odwroceniu wszystkich polaczonych fragmentow otrzymujemy poprawny wynik
		//jednak liczba cyfr wyniku bedzie wielokrotnoscia trojki, czyli moze byc poprzedzona przez 0-2 zer
	string bin_trimmed = "";
	int start = 0;

	for (int i = 0; i < bin.length(); i++)  //ta petla szuka pierwszej jedynki od lewej strony wyniku
	{
		if (bin[i] == '1')
		{
			start = i;  //pozycje 1-ej jedynki zapisujemy do zmiennej
			break;
		}
	}

	for (int i = start; i < bin.length(); i++)  //poczwszy od pozycji wpomnianej jedynki zapisujemy reszte liczby binarnej
		bin_trimmed += bin[i];

	return bin_trimmed;  //zwracamy wynik po ucieciu poczatkowych zer
}