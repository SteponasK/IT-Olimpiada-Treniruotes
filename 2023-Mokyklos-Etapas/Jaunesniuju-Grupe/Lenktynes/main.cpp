#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, t;
	std::cin >> n >> t;
	std::vector<int> times;
	times.push_back(t);
	for (int i = 0; i < n; ++i) {
		int temp{};
		std::cin >> temp;
		times.push_back(temp);
	}
	std::sort(times.begin(), times.end(), std::less<int>());
	for (int i = 0; i < times.size(); ++i) {
		if (times[i] == t) {
			std::cout << i+1;
			break;
		}
	}
	return 0;
}