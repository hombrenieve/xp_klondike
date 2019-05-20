#include "PileBuilder.h"

PileBuilder::PileBuilder() :
    numberValue(0),
    pile(0, cards)
{ }

PileBuilder& PileBuilder::withCard(const Card& card) {
    this->cards.push_back(card);
    return *this;
}

PileBuilder& PileBuilder::number(int number) {
    this->numberValue = number;
    return *this;
}

Pile&& PileBuilder::build() {
    this->pile = Pile(this->numberValue, this->cards);
    return std::move(this->pile);
}