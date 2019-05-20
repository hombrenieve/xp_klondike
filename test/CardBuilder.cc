#include "CardBuilder.h"

CardBuilder::CardBuilder() :
    suitValue(&Suit::HEARTS),
    numberValue(&Number::ACE),
    facedUpValue(false),
    card(suitValue, numberValue)
{ }

Card&& CardBuilder::build() {
    this->card = Card(suitValue, numberValue);
    if(facedUpValue)
        this->card.flip();
    return std::move(this->card);
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