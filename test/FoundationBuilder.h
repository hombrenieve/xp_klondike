#ifndef _FOUNDATIONBUILDER_H_
#define _FOUNDATIONBUILDER_H_
#include "Foundation.h"
#include "Card.h"
#include "Suit.h"

#include <list>

class FoundationBuilder {
public:
    FoundationBuilder();

    FoundationBuilder& suit(const Suit& suit);
    FoundationBuilder& withCard(const Card& card);
    FoundationBuilder& fullSuit();

    Foundation build();

private:
    std::list<Card> cards;
    const Suit* suitValue;
};


#endif