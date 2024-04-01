#include <iostream>
#include <array>

// skaicius dalus is 5 tada, kai jo paskutinis skaitmuo yra 5 arba 0
int main() {
	int n{};
	std::cin >> n;
	std::array<int, 10> nums;
	std::fill(std::begin(nums), std::end(nums), 0);
	for (int i = 0; i < n; ++i) {
		int num{};
		std::cin >> num;
		nums[num]++; // padidiname kiek kartu tas skaicius pasikartojo
	}

	if (nums[0] == 0 && nums[5] == 0) { // jeigu nera 0 ir 5 skaiciaus
		std::cout << "NE";
		return 0;
	}
	std::cout << "TAIP" << std::endl;

	std::array<int, 10> row = { 1, 2, 3, 4, 6, 7, 8, 9, 5, 0 };
	for (int i = 0; i < 10; ++i) {
		int number = row[i]; // skaicius is {1,2,3,4,6,7,8,9,5,0}
		for (int j = 0; j < nums[number]; ++j) {
			std::cout << number << std::endl;
		}
	}
	return 0;
}
