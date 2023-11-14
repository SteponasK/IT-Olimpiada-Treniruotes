#include <iostream>
#include <vector>
#include <algorithm>
std::vector<int> calculateLegalMoves(const int index, std::vector<int>& vec, const int k);
int main() {
	int k{};
	int n{};
	std::cin >> n >> k;
	std::vector<int> vec;
	std::vector<int> pradinis;
	for (int i = 0; i < n; ++i) {
		int temp{};
		std::cin >> temp;
		pradinis.push_back(temp);
	}

		for (int j = 0; j < pradinis.size(); ++j) {
			if (pradinis[j] == 0) {
				std::vector<int> legalMoves = calculateLegalMoves(j, pradinis, k);
				if (!legalMoves.empty()) {
					pradinis[j] = legalMoves[0];
				}
				else {
					std::cout << -1;
					return 0;
				}
			}
		}
	for (int i = 0; i < pradinis.size(); ++i) {
		std::cout << pradinis[i] << ' ';
	}
	return 0;
}
std::vector<int> calculateLegalMoves(const int index, std::vector<int>& vec, const int k) {
	std::vector<int> illegal;
	if (index == 0) {
		// check kad nesikartotu su desiniu kaimynu
		illegal.push_back(vec[index + 1]);
	}
	else if (index + 1 == vec.size()) {
		// check kad nesikartotu su kairiu
		illegal.push_back(vec[index - 1]);
	}
	else {
		illegal.push_back(vec[index + 1]);
		illegal.push_back(vec[index - 1]);
	}
	std::vector<int> legal;
	for (int i = 1; i <= k; ++i) {
	
		bool isIllegal = false;
		for (const auto& illegalMove : illegal) {
			if (illegalMove == i){
				isIllegal = true;
				break;
			}
		}
		if (isIllegal == false) {
			legal.push_back(i);
		}
	}
	return legal;
}