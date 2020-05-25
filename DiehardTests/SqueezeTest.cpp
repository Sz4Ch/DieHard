#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

void SqueezeTest()
{
	int over = 0;
	int below = 0;

	const char* filename = "liczby.txt";
	std::fstream file;
	file.open(filename, std::ios::in);
	int number;
	std::vector<uint8_t> numbers_vec;

	while (!file.eof())
	{
		file >> number;
		numbers_vec.push_back(number);
	}
	file.close();

	std::vector<float> squeezed_numbers_vec(numbers_vec.size());
	std::copy(numbers_vec.begin(), numbers_vec.end(), squeezed_numbers_vec.begin());

	auto floate = [](float& n) {n /= 255.0f; };

	std::for_each(squeezed_numbers_vec.begin(), squeezed_numbers_vec.end(), floate);

	int k = 0;
	int j = 0;

	for (size_t i = 0; i < squeezed_numbers_vec.size(); i++)
	{
		k = 2147483647;
		j = 0;

		while (k >= 1 && k <= 48)
		{
			k = ceil(k * squeezed_numbers_vec.at(i));
			j++;
		}

		if (j < 6) below++;
		else if (j > 48) over++;
		else continue;

	}

	std::cout << "j > 48: " << over << "times.\n" << "j < 6:" << below << "times.";


	return;
}