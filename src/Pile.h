#ifndef _PILE_H_
#define _PILE_H_

#include "CardStack.h"

#include <stack>
#include <list>

class Pile: public CardStack {
public:
    Pile(int number, const std::list<Card>& cards);
    bool fitsIn(const Card& card);
    std::list<Card> getTop(int numberOfCards);
    void addToTop(const std::list<Card>& cards);
    void removeTop(int numberOfCards);
    int getNumberOfFaceUpCards();
    std::stack<Card> getCards();
    int getNumber();
private:
    void flipFirstCard();
    int number;
    int numberOfFaceUpCards;

};


#endif