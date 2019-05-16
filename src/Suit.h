#include "Color.h"

class Suit {
public:

    static Suit HEARTS,
            DIAMONDS,
            CLOVERS,
            PIKES;

    static char* initials();
    static Suit* find(char initial);
    Color* getColor();
private:
    Suit(Color* color, char initial);
    char initial;
    Color* color;
};