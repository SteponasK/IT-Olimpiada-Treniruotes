#include <iostream>

int main()
{
	int n, m, d; // n - pomidorai,  m - raudono pomidoro nr,  d - dienu skaicius 
	std::cin >> n >> m >> d;
	int like{n}; 
	int leftIndex{m-1};
	int rightIndex{ m +1 };
	do {
		if (leftIndex >= 1 && like > 0) {
			--like;
			--leftIndex;
		}
		if (rightIndex <= n && like > 0) {
			--like;
			++rightIndex;
		}
		--d;
	} while ( d >= 1 && like > 0);
	std::cout << like-1;

	return 0;
}