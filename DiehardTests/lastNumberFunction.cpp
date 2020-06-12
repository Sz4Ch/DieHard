#include <iostream>
#include <fstream>
#include <random>
#include <string>

int lastNumberFunction() {
	std::fstream plik("Birthday.txt", std::ios::in);

	std::string line = "";
	int liczba = 0;
	int lenght = 0;
	char c = '\0';
	if (plik) {
		std::cout << "Uzyskano dostep do pliku!" << std::endl;

		lenght = plik.tellg();
		for (int i = lenght; i > lenght - 2; i--) {
			plik.seekg(i);
			c = plik.get();
			if (c == '\n') {
				break;
			}
		}

		std::getline(plik, line);
		plik.close();
		std::cout << line;
		int liczba = atoi(line.c_str());
	}

	return liczba;
}