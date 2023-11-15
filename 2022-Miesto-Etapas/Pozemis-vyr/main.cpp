#include <iostream>
#include <vector>
#include <string>
int level = -1;
void updateLevel(const char newMove);
void addLevelUp(std::string& moveStr);
void addLevelDown(std::string& moveStr);
int main() {
	int count{};
	std::cin >> count;
	std::vector<int> moves;
	std::string moveStr;
	std::cin >> moveStr;
	for (int i = 0; i < moveStr.length(); ++i) {
		updateLevel(moveStr[i]);
		if (level > -1) {
			moveStr.insert(moveStr.begin() + i, 'L');
			--level;
			++i;
		}
	}
	if (level < -1) {
		addLevelUp(moveStr);
	}
	else if (level > -1) {
		addLevelDown(moveStr);
	}
	std::cout << moveStr.length() << std::endl;
	std::cout << moveStr;
	return 0;
}
void updateLevel(const char newMove) {
	switch (newMove) {
	case 'L':
		--level;
		break;
	case 'K':
		++level;
	default:
		break;
	}
}
void addLevelUp(std::string& moveStr) {
	while (level < -1)
	{
		moveStr.insert(moveStr.end(), 'K');
		++level;
	}
}
void addLevelDown(std::string& moveStr) {
	while (level > -1)
	{
		moveStr.insert(moveStr.end(), 'L');
		--level;
	}
}