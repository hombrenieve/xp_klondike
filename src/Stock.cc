#include "Stock.h"
#include <random>
#include <algorithm>
#include <iterator>

Stock::Stock()
{ 
    for(const auto initial: Suit::initials()) {
        const Suit* suit = Suit::find(initial);
        for(int i = 0; i < Number::DECK_LENGTH; i++) {
            const Number* number = Number::find(i);
            this->push(Card(suit, number));
        }
    }
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
 
    std::shuffle(this->cards.begin(), this->cards.end(), generator);
}

std::list<Card> Stock::takeTop(int quantity) {
    std::list<Card> stockCards;
    while(quantity > 0 && not this->empty()) {
        stockCards.push_back(this->pop());
        quantity--;
    }
    return stockCards;
}