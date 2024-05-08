#include <iostream>
#include <algorithm>
#include <chrono>
#include <string>

void fill_array(int* arr, int size);  //wypelnia tablice
void selectionSort(int* arr, int n); //funkcje sortujace
void bubbleSort(int arr[], int n);
void quick_sort(int* tab, int lewy, int prawy);
void heapify(int arr[], int n, int i);  //pomocnicza dla heap sort
void heapSort(int arr[], int n);
std::string count_time(int* arr, int size, int func); //liczy czas


int main()
{
	const int ARRAY_COUNT = 5;
	int size[ARRAY_COUNT] = { 1000, 10000, 30000, 60000, 100000 };  //Wielkosci tablic

	for (int i = 0; i < ARRAY_COUNT; i++)
	{
		int* arr = new int[size[i]];  //tworzy tablice dla wielkosci wybranej przez petle
		fill_array(arr, size[i]);  //wypelnia tablice losowymi elementami

		std::cout << "Dla " << size[i] << " elementow: \n";
		std::cout << "Funkcja; \tczas w s;\n";

		for (int j = 0; j < 4; j++)
			std::cout << count_time(arr, size[i], j) << "\n";  //ta funkcja przeprowadza test dla wskazanej funkcji sortujacej 0-3 z uzyciem naszej tabeli

		std::cout << "\n";
	}

	return 0;
}

void fill_array(int* arr, int size)  //wypelnia tablice losowymi wartosciami z przedzialu 1 - 1000;
{
	srand(time(NULL));

	for (int i = 0; i < size; i++)
		arr[i] = (rand() % 1000) + 1;
}

//funkcja do liczenia czasu
std::string count_time(int* arr, int size, int func)
{
	int* arrayCp = new int[size];
	std::copy(arr, arr + size, arrayCp);  //dzialamy na kopii, nie oryginale. W ten sposob wszystkie funkcje sortujace dostana dokladnie ta sama tablice do testu

	std::string fname;
	auto start = std::chrono::high_resolution_clock::now();  //zaczynamy liczenie czasu

	switch (func)  //wybor funkcji sortujacej
	{
	case 0:
		fname = "Bubble Sort";
		bubbleSort(arrayCp, size);
		break;
	case 1:
		fname = "Selection Sort";
		selectionSort(arrayCp, size);
		break;
	case 2:
		fname = "Quick Sort";
		quick_sort(arrayCp, 0, size - 1);
		break;
	case 3:
		fname = "Heap Sort";
		heapSort(arrayCp, size);
		break;
	default:
		fname = "Brak funckcji";
	}
	
	auto stop = std::chrono::high_resolution_clock::now(); //konczymy liczenie czasu
	auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);  //obliczamy czas

	return fname + "\t" + std::to_string(duration.count() * 1e-9);
}


//funkcje sortujace
void selectionSort(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		int min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
				min = j;
		}

		std::swap(arr[i], arr[min]);
	}
}


//funkcje do sortowania pozyczone z googla
void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
}

void quick_sort(int* tab, int lewy, int prawy)
{
	if (prawy <= lewy) return;

	int i = lewy - 1, j = prawy + 1,
		pivot = tab[(lewy + prawy) / 2]; //wybieramy punkt odniesienia

	while (1)
	{
		//szukam elementu wiekszego lub rownego piwot stojacego
		//po prawej stronie wartosci pivot
		while (pivot > tab[++i]);

		//szukam elementu mniejszego lub rownego pivot stojacego
		//po lewej stronie wartosci pivot
		while (pivot < tab[--j]);

		//jesli liczniki sie nie minely to zamieñ elementy ze soba
		//stojace po niewlasciwej stronie elementu pivot
		if (i <= j)
			//funkcja swap zamienia wartosciami tab[i] z tab[j]
			std::swap(tab[i], tab[j]);
		else
			break;
	}

	if (j > lewy)
		quick_sort(tab, lewy, j);
	if (i < prawy)
		quick_sort(tab, i, prawy);
}

//pomocnicza funkcja heapsort
void heapify(int arr[], int n, int i) {
	// Find largest among root, left child and right child
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	// Swap and continue heapifying if root is not largest
	if (largest != i) {
		std::swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

// glowna funkcja heap sort
void heapSort(int arr[], int n) {
	// Build max heap
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// Heap sort
	for (int i = n - 1; i >= 0; i--) {
		std::swap(arr[0], arr[i]);

		// Heapify root element to get highest element at root again
		heapify(arr, i, 0);
	}
}