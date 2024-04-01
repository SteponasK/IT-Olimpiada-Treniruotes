#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
int main() {
	int n{};
	std::cin >> n;
	std::vector<int> square;
	for (int i = 0; i < n*n; ++i) {
		int value{};
		std::cin >> value;
		square.push_back(value);
	}
	std::vector<int> sumVec;
	for (int i = 0; i < n; ++i) { // suskaiciuojame eiles
		int sum{ 0 };
		for (int j = 0; j < n; ++j) {
			int index = i * n + j;
			sum += square[index];
		}
		sumVec.push_back(sum);
	}
	for (int i = 0; i < n; ++i) { // suskaiciuojame stulpelius
		int sum{ 0 };
		for (int j = 0; j < n; ++j) {
			int index = j * n + i;
			sum += square[index];
		}
		sumVec.push_back(sum);
	}
	int sum = 0;
	// istrizai is kaires apacios
	for (int i = 0; i < n; ++i) {
		int index = (n - 1 - i) * n + i;
		sum += square[index];
	}
	sumVec.push_back(sum);
	sum = 0;
	// istrizai is kaires virsaus
	for (int i = 0; i < n; ++i) {
		 int index = i * n + i;
		 sum += square[index];
	}
	sumVec.push_back(sum);
	
	std::sort(sumVec.begin(), sumVec.end(), std::greater<int>());
	int min = sumVec[0];
	int max = sumVec[0];
	for (int i = 1; i < sumVec.size(); ++i) {
		if (sumVec[i] > max) max = sumVec[i];
		if (sumVec[i] < min ) min = sumVec[i];
		if (sumVec[i]+1 != sumVec[i - 1]) {
			std::cout << '0';
			return 0;
		}
	}
	std::cout << min << ' ' << max;
	return 0;
}