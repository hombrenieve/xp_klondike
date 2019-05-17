#ifndef _CARDSTACK_H_
#define _CARDSTACK_H_

#include "Card.h"
#include <stack>

class CardStack {
public:
    CardStack();
    virtual ~CardStack();
    virtual bool empty();
    virtual Card peek();
    virtual Card pop();
    virtual void push(const Card& card);
private:
    std::stack<Card> cards;
};

#endif
