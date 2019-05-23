#ifndef _NUMBER_H_
#define _NUMBER_H_

#include <array>

class Number {
public:
    static const int DECK_LENGTH = 13;

    static Number ACE;
    static Number TWO;
    static Number THREE;
    static Number FOUR;
    static Number FIVE;
    static Number SIX;
    static Number SEVEN;
    static Number EIGHT;
    static Number NINE;
    static Number TEN;
    static Number JACK;
    static Number QUEEN;
    static Number KING;

    int getValue() const;
    static const Number* find(int n);

private:
    Number(int value);
    int value;

    static std::array<const Number*, DECK_LENGTH> numbers;
};

#endif
