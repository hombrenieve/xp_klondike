#ifndef _NUMBER_H_
#define _NUMBER_H_

class Number {
public:

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

private:
    Number(int value);
    int value;
};

#endif
