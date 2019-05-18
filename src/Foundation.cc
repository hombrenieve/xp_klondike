#include "Foundation.h"

Foundation::Foundation(const Suit* suit) :
    suit(suit)
{ }

bool Foundation::isComplete() const {
    return false;
}

bool Foundation::fitsIn(const Card& card) const {
    return false;
}

const Suit* Foundation::getSuit() const {
    return suit;
}