#include <iostream>
#include <fstream>
#include <random>
#include <string>




void BirthdaySpacingTestNextPart()
{
	std::fstream plik("Birthday.txt", std::ios::in);

	std::fstream result("policzoneBday.txt", std::ios::out);
	result.close();
	if (plik) {
		std::cout << "Uzyskano dostep do pliku!" << std::endl;

		int liczba;
		int count = 0;
		plik.close();
		//std::cout << a << std::endl;
		for (int i = 0; i <= 5; i++) {
			count = 0;
			std::fstream plik("Birthday.txt", std::ios::in);
			while (!plik.eof()) {
				plik >> liczba;
				//std::cout << liczba << std::endl;
				if (liczba == i) {
					count++;
				}

			}
			std::fstream result("policzoneBday.txt", std::ios_base::app);
			result << i << "\t" << count << "\n";
			plik.close();
		}

		result.close();
	}
	else {
		std::cout << "Brak dostepu do pliku " << std::endl;
	}

	plik.close();

	std::cout << "Koniec" << std::endl;

}
