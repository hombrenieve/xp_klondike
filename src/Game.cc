#include "Game.h"

Game::Game()
{
    this->initializePiles();
    this->initializeFoundations();
}

void Game::clear() {
    this->waste = Waste();
    this->stock = Stock();
    this->initializePiles();
    this->initializeFoundations();
}

void Game::initializeFoundations() {
    for(const auto initial: Suit::initials()) {
        const Suit* suit = Suit::find(initial);
        this->foundations.emplace(std::make_pair(suit, suit));
    }
}

void Game::initializePiles() {
    for(int i = 0; i < Game::NUMBER_OF_PILES; i++) {
        Pile pile(i, this->getStock().takeTop(i+1));
        pile.peek().flip();
        this->piles.push_back(pile);
    }
}

bool Game::isFinished() const {
   return false;
}

const Error* Game::moveFromStockToWaste() {
    return nullptr;
}

const Error* Game::moveFromWasteToFoundation(const Suit* suit) {
    return nullptr;
}

const Error* Game::moveFromWasteToStock() {
    return nullptr;
}

const Error* Game::moveFromWasteToPile(int pileIndex) {
    return nullptr;
}

const Error* Game::moveFromFoundationToPile(const Suit* suit, int pileIndex) {
    return nullptr;
}

const Error* Game::moveFromPileToFoundation(int pileIndex, const Suit* suit) {
    return nullptr;
}

const Error* Game::moveFromPileToPile(int originIndex, int destinationIndex, int numberOfCards) {
    return nullptr;
}

Stock& Game::getStock() {
    return this->stock;
}

Waste& Game::getWaste() {
    return this->waste;
}

std::map<const Suit*, Foundation>& Game::getFoundations() {
    return this->foundations;
}

std::list<Pile>& Game::getPiles() {
    return this->piles;
}
