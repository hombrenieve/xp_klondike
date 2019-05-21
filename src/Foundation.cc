#include "Foundation.h"

Foundation::Foundation(const Suit* suit) :
    suit(suit)
{ }

bool Foundation::isComplete() {
    if(not this->empty() and
        this->peek().getNumber() == &Number::ACE and
        this->cards.size() == Number::KING.getValue())
        return true;
    return false;
}

bool Foundation::fitsIn(const Card& card) {
    if(not this->empty() and
        this->peek().isNextTo(card) and
        (this->peek().getSuit() == card.getSuit())) {
            return true;
    }
    return false;
}

const Suit* Foundation::getSuit() const {
    return suit;
}