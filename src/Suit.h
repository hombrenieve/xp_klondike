#ifndef _SUIT_H_
#define _SUIT_H_


#include "Color.h"

#include <string>

class Suit {
public:

    static Suit HEARTS,
            DIAMONDS,
            CLOVERS,
            PIKES;

    static const std::string& initials();
    static const Suit* find(char initial);
    const Color* getColor() const;
private:
    Suit(Color* color, char initial);
    char initial;
    Color* color;
    static std::string initialsString;
};

#endif
