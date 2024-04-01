#include <iostream>
#include <vector>
#include <unordered_map>
std::vector<int> deck;
int deckCount = 0;
void calculateDeck(int& newCard);
bool isMin(int& card);
int findNextSmallerValue(int& card);
int main() {

	int n{};
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int card{};
		std::cin >> card;
		calculateDeck(card);
	}
	std::cout << deckCount << std::endl;

	for (auto const& card : deck) {
		std::cout << card << std::endl;
	}
	return 0;
}
bool isMin(int& newCard){
	for (auto const& card : deck) {
		if (newCard >= card) {
			return false;
		}
	}
	return true;
}
void calculateDeck(int& newCard) {
	if (isMin(newCard))
	{
		 ++deckCount;
		 deck.push_back(newCard);
	}
	else {
		int index =  findNextSmallerValue(newCard);
		deck[index] = newCard;
	}
}
int findNextSmallerValue(int& card) {
	int smallest_diff = 101;
	int index = 0;
	for (int i = deck.size() - 1; i >= 0; --i) {
		if (card - deck.at(i) < smallest_diff && card - deck.at(i) > 0) {
			smallest_diff = card - deck.at(i);
			index = i;
		}
	}
	return index;
}