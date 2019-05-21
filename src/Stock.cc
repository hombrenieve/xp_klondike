#include "Stock.h"

Stock::Stock()
{ }

std::list<Card> Stock::takeTop(int quantity) {
    std::list<Card> stockCards;
    while(quantity > 0 && not this->empty()) {
        stockCards.push_back(this->pop());
        quantity--;
    }
    return stockCards;
}