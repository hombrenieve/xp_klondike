#ifndef __STOCKBUILDER_H_
#define __STOCKBUILDER_H_

#include "Stock.h"
#include <list>

class StockBuilder {
public:
    StockBuilder();

    StockBuilder& withCard(const Card& card);

    Stock build();

private:
    std::list<Card> cards;
};

#endif