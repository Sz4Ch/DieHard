#include <iostream>
#include <fstream>
#include <random>
#include <string>


void SqueezeTestv2()
{
	std::fstream plik("liczby.txt", std::ios::in);

	std::fstream result("zliczanieJ.txt", std::ios::out);
	result.close();

	if (plik) {
		std::cout << "Uzyskano dostep do pliku!" << std::endl;

		float liczba;
		while (!plik.eof()) {
			plik >> liczba;
			//std::cout << a << std::endl;
			int k = 2147483647;
			int j = 0;
			liczba = liczba / 256;

			while ((k != 1) && (j < 48)) {

				k = ceil(k * liczba);
				j++;

			}
			j = (j < 6) ? 6 : j;
		std::fstream result("zliczanieJ.txt", std::ios_base::app);
		result << j << "\n";
		result.close();
		}	

	}else {
		std::cout << "Brak dostepu do pliku " << std::endl;
	}
	plik.close();
	std::cout << "Koniec" << std::endl;

}
