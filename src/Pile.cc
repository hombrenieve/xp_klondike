#include "Pile.h"

Pile::Pile(int number, const std::list<Card>& cards) :
    number(0),
    numberOfFaceUpCards(0)
{ }

bool Pile::fitsIn(const Card& card) {
    return false;
}

std::list<Card> Pile::getTop(int numberOfCards) {
    return std::list<Card>();
}

void Pile::addToTop(const std::list<Card>& cards) {
}

void Pile::removeTop(int numberOfCards) {

}

int Pile::getNumberOfFaceUpCards() {
    return numberOfFaceUpCards;
}

std::stack<Card> Pile::getCards() {
    return cards;
}

int Pile::getNumber() {
    return number;
}

void Pile::flipFirstCard() {
}