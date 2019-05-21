#include "CardBuilder.h"

CardBuilder::CardBuilder() :
    suitValue(&Suit::HEARTS),
    numberValue(&Number::ACE),
    facedUpValue(false)
{ }

Card CardBuilder::build() {
    Card card(suitValue, numberValue);
    if(facedUpValue)
        card.flip();
    return card;
}

CardBuilder& CardBuilder::number(const Number& number) {
    this->numberValue = &number;
    return *this;
}

CardBuilder& CardBuilder::suit(const Suit& suit) {
    this->suitValue = &suit;
    return *this;
}

CardBuilder& CardBuilder::facedUp(bool facedUp) {
    this->facedUpValue = facedUp;
    return *this;
}