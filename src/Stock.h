#ifndef _STOCK_H_
#define _STOCK_H_

#include "CardStack.h"
#include "Card.h"
#include <list>

class Stock: public CardStack {
public:
    Stock();
    std::list<Card> takeTop(int quantity);
};

#endif