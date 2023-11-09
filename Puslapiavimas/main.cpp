#include <iostream>
#include <vector>
#include <unordered_set>
int main() {
	int skaicius{};
	int talpa{};
	std::cin >> skaicius >> talpa;
	std::vector<std::vector<std::string>> vardai;
	std::vector <std::unordered_set<char>> Sarasai;
	
	for (int i = 0; i < skaicius/talpa  + (skaicius%talpa ? 1 : 0); ++i) {
		std::unordered_set<char> raides{};
		for (int j = 0; j < talpa; ++j) {
			std::string tempStr{};
			std::cin >> tempStr;
			raides.insert(tempStr[0]);
		}
		Sarasai.push_back(raides);
	}
	int max{ 0 };
	for (const auto& currSarasas : Sarasai) {
		if (currSarasas.size() > max){
			max = currSarasas.size();
		}
	}
	std::cout << max;
	
	return 0;
}