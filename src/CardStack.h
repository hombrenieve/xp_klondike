#ifndef _CARDSTACK_H_
#define _CARDSTACK_H_

#include "Card.h"
#include <deque>

class CardStack {
public:
    CardStack();
    virtual ~CardStack();
    virtual bool empty();
    virtual Card& peek();
    virtual Card pop();
    virtual void push(const Card& card);
protected:
    std::deque<Card> cards;
};

#endif
