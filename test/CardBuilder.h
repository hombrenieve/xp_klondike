#ifndef _CARDBUILDER_H_
#define _CARDBUILDER_H_

#include "Card.h"

class CardBuilder {
public:
    CardBuilder();
    Card build();
    CardBuilder& number(const Number& number);
    CardBuilder& suit(const Suit& suit);
    CardBuilder& facedUp(bool facedUp);
private:
    const Suit* suitValue;
    const Number* numberValue;
    bool facedUpValue;
};

#endif
