#include <cmath>
#include <iostream>
#include <string>
#include <fstream> //file stream

using namespace std;

int* extend(int* a, int size, int newsize) {
	int* b = new int[newsize];
	for (int i = 0; i < size; i++)
		b[i] = a[i];
	delete[] a;
	return b;
}

void printArray(int* a, int size) {
	for (int i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main1() {
	ifstream file("liczby.txt");
	//int liczba;
	int size = 10;
	int* t = new int[size];
	int i = 0;
	while (file >> t[i]) {
		++i;
		if (i == size) {
			t = extend(t, size, size * 2); //{4,5,4,6,4, , , , , } 
			size *= 2;
		}
	}
	//nie wyswietla pustych miejsc gdy tablica ma ich wiejcej niz liczb w pliku
	//wyswietl tyle ile wynosi i (indeks wczytanej liczby) po ostatnim wczytaniu
	printArray(t, i);
	//printf("liczba 6 w t: %i", t[6]);
	delete[] t;
	return 0;
}

int main2() {
	//plik otwarty do zapisu automatycznie utworzy sie jesli nie istnieje
	/*ofstream file("f.txt");
	int zm;
	cin >> zm;
	if (file.good()) {
		file << "napis testowy" <<endl <<zm;
	}*/

	//jesli plik otwarty do odczytu nie istnieje to po prostu nie mozemy z niego czytac
	/*ifstream file("Source.cpp");
	if (file.good()) {
		string line;
		while (getline(file, line)) { //czyta linie ale nie bierze pod uwage znaku \n
			cout << line << endl;
		}
		//file >> s; //odczytuje jeden wyraz (do pierwszego bialego znaku)
	}
	file.close();
	*/
	return 0;
}

int main3() {
	// Napisz program, który prosi u¿ytkownika o nazwê pliku, iloœæ liczb oraz wartoœæ min i max.
	//Nastepnie otwiera plik do zapisu o podanej nazwie i wpisuje do niego tyle liczb 
	//o losowych wartoœciach z przedzia³u [min, max].

	string nazwaPliku;
	int iloscliczb;
	int min;
	int max;
	int liczby = 0;


	cout << "podaj nazwe pliku, ilosc liczb oraz wartosc min i max" << endl;
	cin >> nazwaPliku >> iloscliczb >> min >> max;

	ofstream file(nazwaPliku);
	if (file.good()) {
		for (int i = 0; i <= iloscliczb; i++)
			liczby = rand() % (max - min + 1);
		file << liczby;
		return 0;
	}

}

int main() {

	//	Napisz program, który prosi o podanie 2 nazw plików i kopiuje zawartoœæ jednego z nich 
	//  do drugiego (nowego) pliku o podanej nazwie.

	string plik1;
	string plik2;
	cout << "podaj nazwy plikow" << endl;
	cin >> plik1 >> plik2;

	ifstream file1(plik1);
	ofstream file2(plik2);
	string line;
	if (file1.good() && file2.good())
	{

		string line;

		while (getline(file1, line)) {
			file2 << line << endl;

		}
	}
	//	Napisz program, który dzieli plik na pó³, tzn pobiera nazwê pliku od u¿ytkownika, 
	//	wczytuje jego zawartoœæ i zapisuje
	//	po po³owie w 2 nowych plikach o nazwach takich nazwa pliku wejœciowego z dopiskiem "_part1" i "_part2".

}


