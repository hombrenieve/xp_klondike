 #include "GameBuilder.h"
 
GameBuilder::GameBuilder()
{ 
    for(int i = 0; i < Game::NUMBER_OF_PILES; i++) {
        this->piles.emplace_back(i, std::list<Card>());
    }
}

GameBuilder& GameBuilder::stock(const Stock& stock) {
    this->stockValue = stock;
    return *this;
}

GameBuilder& GameBuilder::waste(const Waste& waste) {
    this->wasteValue = waste;
    return *this;
}

GameBuilder& GameBuilder::addToWaste(const Card& card) {
    this->wasteValue.push(card);
    return *this;
}

GameBuilder& GameBuilder::foundation(const Suit& suit, const Foundation& foundation) {
    this->foundations.insert({&suit, foundation});
    return *this;
}

GameBuilder& GameBuilder::pile(int position, const Pile& pile) {
    auto pileIterator = piles.begin();
    std::advance(pileIterator, position);
    *pileIterator = pile;
    return *this;
}

Game GameBuilder::build() {
    Game game;
    game.getStock() = this->stockValue;
    game.getWaste() = this->wasteValue;
    for(const auto& foundation: this->foundations) {
        game.getFoundations().insert(foundation);
    }
    game.getPiles() = this->piles;
    return game;
}