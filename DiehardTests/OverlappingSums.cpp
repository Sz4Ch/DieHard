#include <fstream>
#include <algorithm>
#include <vector>
#include <ranges>

template <long FROM, long TO>
class Range
{
public: 
	class iterator : public std::iterator<
		std::input_iterator_tag,
		long,
		long,
		const long*,
		long >
	{
		long num = FROM;
	public:
		explicit iterator(long _num = 0) : num(_num) {}
		iterator& operator++() { num = TO >= FROM ? num + 1 : num - 1; return *this; }
		iterator operator++(int) { iterator retval = *this; ++(*this); return retval; }
		bool operator==(iterator other) const { return num == other.num; }
		bool operator!=(iterator other) const { return !(*this == other); }
		reference operator*() const { return num; }
	};

	iterator begin() { return iterator(FROM); }
	iterator end() { return iterator(TO >= FROM ? TO + 1 : TO - 1); }
};

void OverlappingSumsTest()
{
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


	std::vector<float> floated_numbers_vec(numbers_vec.size());
	std::copy(numbers_vec.begin(), numbers_vec.end(), floated_numbers_vec.begin());

	auto floate = [](float& n) {n /= 255.0f; };

	std::for_each(floated_numbers_vec.begin(), floated_numbers_vec.end(), floate);

	std::vector<float> sums_vec;
	
	long start = 0;
	long end = 100;
	auto range = Range<start, end>();
	auto Sum = [&](const float n) { sums_vec.end() += n; };
	
	while (true)
	{
		sums_vec.push_back(0.0f);
		std::for_each(range.begin(), range.end(), Sum);
		


	}

	return;

}