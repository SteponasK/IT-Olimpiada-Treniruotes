#include <iostream>
#include <vector>
#include <algorithm>
void getData();
void removeDuplicates();
int N{};
std::vector<int> rutuliai;
int main() {
	getData();
	std::sort(rutuliai.begin(), rutuliai.end(), std::less<int>());
	removeDuplicates();
	
	std::cout << rutuliai.size() << std::endl;
	for (const auto& rutulys : rutuliai) {
		std::cout << rutulys << std::endl;
	}
	return 0;
}
void getData() {
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		int skaicius{};
		std::cin >> skaicius;
		rutuliai.push_back(skaicius);
	}
}
void removeDuplicates() {
	if (N == 1) return;
	for (int i = 1; i < rutuliai.size(); ++i) {
		if (rutuliai[i] == rutuliai[i - 1]) {
			rutuliai.erase(rutuliai.begin() + i);
			rutuliai.erase(rutuliai.begin() + i - 1);
			--i;
		}
	}
}