#include "CardStack.h"
#include <cassert>

CardStack::CardStack()
{ }

CardStack::~CardStack()
{ }

bool CardStack::empty() {
    return cards.empty();
}

Card& CardStack::peek() {
    assert(not this->empty());
    return this->cards.front();
}

Card CardStack::pop() {
    assert(not this->empty());
    Card card = this->peek();
    this->cards.pop_front();
    return card;
}

void CardStack::push(const Card& card) {
    this->cards.push_front(card);
}