#include "Stock.h"

Stock::Stock()
{ 
    for(const auto initial: Suit::initials()) {
        const Suit* suit = Suit::find(initial);
        for(int i = 0; i < Number::DECK_LENGTH; i++) {
            const Number* number = Number::find(i);
            this->push(Card(suit, number));
        }
    }
}

std::list<Card> Stock::takeTop(int quantity) {
    std::list<Card> stockCards;
    while(quantity > 0 && not this->empty()) {
        stockCards.push_back(this->pop());
        quantity--;
    }
    return stockCards;
}