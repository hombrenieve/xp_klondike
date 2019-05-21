#include "PileBuilder.h"

PileBuilder::PileBuilder() :
    numberValue(0)
{ }

PileBuilder& PileBuilder::withCard(const Card& card) {
    this->cards.push_back(card);
    return *this;
}

PileBuilder& PileBuilder::number(int number) {
    this->numberValue = number;
    return *this;
}

Pile PileBuilder::build() {
    return Pile(this->numberValue, this->cards);
}