#include "Suit.h"

Suit Suit::HEARTS(&Color::RED, 'h'), 
    Suit::DIAMONDS(&Color::RED, 'd'), 
    Suit::CLOVERS(&Color::BLACK, 'c'), 
    Suit::PIKES(&Color::BLACK, 'p');

std::string Suit::initialsString{ "hdcp" };

Suit::Suit(Color* color, char initial) : 
    color(color),
    initial(initial)
{ }

const std::string& Suit::initials() {
    return initialsString;
}
    
const Suit* Suit::find(char initial) {
    switch(initial) {
        case 'h':
            return &HEARTS;
        case 'd':
            return &DIAMONDS;
        case 'c':
            return &CLOVERS;
        case 'p':
            return &PIKES;
        default:
            break;
    }
    return nullptr;
}

const Color* Suit::getColor() const {
    return color;
}