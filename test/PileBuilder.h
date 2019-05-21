#ifndef _PILEBUILDER_H_
#define _PILEBUILDER_H_

#include "Pile.h"
#include "Card.h"
#include <list>

class PileBuilder {
public:
    PileBuilder();
    PileBuilder& withCard(const Card& card);
    PileBuilder& number(int number);

    Pile build();

private:
    std::list<Card> cards;
    int numberValue;
};


#endif