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
	
	int offset = 100; //range width

	std::vector<float>::iterator start = floated_numbers_vec.begin();
	std::vector<float>::iterator end = start + offset;

	auto Sum = [&](const float n) { *(sums_vec.end() - 1) += n; };
	
	while (end != floated_numbers_vec.end())
	{
		sums_vec.push_back(0.0f); //new sum
		std::for_each(start, end, Sum); //sum in range start - end

		start++;
		end = start + offset;
	}

	sums_vec.push_back(0.0f); //last sum
	std::for_each(start, end, Sum);

	std::fstream result("OverlappingSums.txt", std::ios::out);
	
	std::for_each(sums_vec.begin(), sums_vec.end(), [&](const float n) { result << n << "\n"; });

	return;
}