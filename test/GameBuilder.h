#ifndef __GAMEBUILDER_H_
#define __GAMEBUILDER_H_

#include "Game.h"
#include "Stock.h"
#include "Waste.h"
#include "Foundation.h"
#include "Pile.h"

#include <map>
#include <list>

class GameBuilder {
public:
    GameBuilder();
    GameBuilder& stock(const Stock& stock);
    GameBuilder& waste(const Waste& waste);
    GameBuilder& addToWaste(const Card& card);
    GameBuilder& foundation(const Suit& suit, const Foundation& foundation);
    GameBuilder& pile(int position, const Pile& pile);

    Game build();

private:
    Stock stockValue;
    Waste wasteValue;
    std::map<const Suit*, Foundation> foundations;
    std::list<Pile> piles;
};


#endif