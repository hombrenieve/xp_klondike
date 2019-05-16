#include "Suit.h"

Suit Suit::HEARTS(&Color::RED, 'h'), 
    Suit::DIAMONDS(&Color::RED, 'd'), 
    Suit::CLOVERS(&Color::BLACK, 'c'), 
    Suit::PIKES(&Color::BLACK, 'p');

Suit::Suit(Color* color, char initial) : 
    color(color),
    initial(initial)
{ }

char* Suit::initials() {
    return nullptr;
}
    
Suit* Suit::find(char initial) {
    return &DIAMONDS;
}

Color* Suit::getColor() {
    return &Color::BLACK;
}