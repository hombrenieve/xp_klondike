#ifndef _CARD_H_
#define _CARD_H_


#include "Suit.h"
#include "Number.h"

class Card {
public:
    Card(const Suit* suit, const Number* number);
    Card* flip();
    bool isNextTo(const Card& card);
    bool isFacedUp() const;
    const Number* getNumber() const;
    const Suit* getSuit() const;
    const Color* getColor() const;
    bool operator==(const Card& other) const;
private:
    const Suit* suit;
    const Number* number;
    bool facedUp;
};

#endif