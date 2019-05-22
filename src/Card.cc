#include "Card.h"

Card::Card(const Suit* suit, const Number* number) :
    suit(suit),
    number(number),
    facedUp(false)
{ }

Card* Card::flip() {
    this->facedUp = not this->isFacedUp();
    return this;
}

bool Card::isNextTo(const Card& card) {
    return card.getNumber()->getValue() + 1 == this->getNumber()->getValue();
}

bool Card::isFacedUp() const {
    return facedUp;
}

const Number* Card::getNumber() const {
    return number;
}

const Suit* Card::getSuit() const {
    return suit;
}

const Color* Card::getColor() const {
    return this->getSuit()->getColor();
}

bool Card::operator==(const Card& other) const {
    return this->getNumber() == other.getNumber() and
        this->getSuit() == other.getSuit();
}