#include <fstream>
#include <algorithm>
#include <vector>
#include <unordered_map>

void BirthdaySpacingsTest()
{
	std::fstream file;
	file.open("liczby.txt", std::ios::in);

	std::vector<uint8_t> numbers_vec;
	int number;
	int t = 0;

	while (!file.eof())
	{
		file >> number;
		numbers_vec.push_back(number);
		t++;
	}
	file.close();

	std::sort(numbers_vec.begin(), numbers_vec.end());

	std::vector<uint8_t> spacings_vec;
	size_t count = 0;
	auto space = [&](const uint8_t n) 
	{ 
		spacings_vec.push_back(n - numbers_vec[count]); 
		++count;
	};

	std::for_each(numbers_vec.begin() + 1, numbers_vec.end(), space);

	std::sort(spacings_vec.begin(), spacings_vec.end());

	std::vector<int> no_equal_spacings_vec(10);

	auto count_spacings = [&](const uint8_t n) { no_equal_spacings_vec[n]++; };

	std::for_each(spacings_vec.begin(), spacings_vec.end(), count_spacings);

	return;

}

