#include "Number.h"

Number Number::ACE(1);
Number Number::TWO(2);
Number Number::THREE(3);
Number Number::FOUR(4);
Number Number::FIVE(5);
Number Number::SIX(6);
Number Number::SEVEN(7);
Number Number::EIGHT(8);
Number Number::NINE(9);
Number Number::TEN(10);
Number Number::JACK(11);
Number Number::QUEEN(12);
Number Number::KING(13);

Number::Number(int value) : value(value)
{ }

int Number::getValue() {
    return this->value;
}