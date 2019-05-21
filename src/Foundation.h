#ifndef _FOUNDATION_H_
#define _FOUNDATION_H_
#include "CardStack.h"
#include "Suit.h"
#include "Card.h"

class Foundation: public CardStack {
public:
    Foundation(const Suit* suit);
    bool isComplete();
    bool fitsIn(const Card& card);
    const Suit* getSuit() const;
private:
    const Suit* suit;
};

#endif