#include "FoundationBuilder.h"
#include "CardBuilder.h"

FoundationBuilder::FoundationBuilder() :
    suitValue(&Suit::HEARTS)
{ }

FoundationBuilder& FoundationBuilder::suit(const Suit& suit) {
    this->suitValue = &suit;
    return *this;
}

FoundationBuilder& FoundationBuilder::withCard(const Card& card) {
    this->cards.push_back(card);
    return *this;
}

FoundationBuilder& FoundationBuilder::fullSuit() {
    CardBuilder cardBuilder;
    cardBuilder.suit(*this->suitValue).facedUp(true);
    this->
        withCard(cardBuilder.number(Number::KING).build()).
        withCard(cardBuilder.number(Number::QUEEN).build()).
        withCard(cardBuilder.number(Number::JACK).build()).
        withCard(cardBuilder.number(Number::TEN).build()).
        withCard(cardBuilder.number(Number::NINE).build()).
        withCard(cardBuilder.number(Number::EIGHT).build()).
        withCard(cardBuilder.number(Number::SEVEN).build()).
        withCard(cardBuilder.number(Number::SIX).build()).
        withCard(cardBuilder.number(Number::FIVE).build()).
        withCard(cardBuilder.number(Number::FOUR).build()).
        withCard(cardBuilder.number(Number::THREE).build()).
        withCard(cardBuilder.number(Number::TWO).build()).
        withCard(cardBuilder.number(Number::ACE).build());
    return *this;
}

Foundation FoundationBuilder::build() {
    Foundation foundation(this->suitValue);
    for(const Card& card: this->cards) {
        foundation.push(card);
    }
    this->cards.clear();
    return foundation;
}