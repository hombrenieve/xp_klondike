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
    const Color* getColor();
private:
    Suit(Color* color, char initial);
    char initial;
    Color* color;
    static std::string initialsString;
};