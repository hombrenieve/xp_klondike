#include "Pile.h"

Pile::Pile(int number, const std::list<Card>& cards) :
    number(number),
    numberOfFaceUpCards(0)
{
    this->addToTop(cards); 
}

bool Pile::fitsIn(const Card& card) {
    if(this->peek().isNextTo(card) and
        (this->peek().getSuit()->getColor() !=
        card.getSuit()->getColor())) {
            return true;
    }
    return false;
}

std::list<Card> Pile::getTop(int numberOfCards) {
    std::list<Card> topCards;
    for(const auto& card: this->cards) {
        if(numberOfCards == 0)
            return topCards;
        topCards.push_back(card);
        numberOfCards--;
    }
    return topCards;
}

void Pile::addToTop(const std::list<Card>& cards) {
    for(const auto& card: cards) {
        this->push(card);
        if(card.isFacedUp())
            numberOfFaceUpCards++;
    }
}

void Pile::removeTop(int numberOfCards) {
    while(numberOfCards > 0 && not this->empty()) {
        Card card = this->pop();
        numberOfCards--;
        if(card.isFacedUp())
            numberOfFaceUpCards--;
    }
    if(not this->empty()) {
        this->flipFirstCard();
    }
}

int Pile::getNumberOfFaceUpCards() {
    return numberOfFaceUpCards;
}

const std::deque<Card>& Pile::getCards() {
    return cards;
}

int Pile::getNumber() {
    return number;
}

void Pile::flipFirstCard() {
    this->peek().flip();
    if(this->peek().isFacedUp()) {
        numberOfFaceUpCards++;
    } else {
        numberOfFaceUpCards--;
    }
}