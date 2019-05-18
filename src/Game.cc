#include "Game.h"

Game::Game()
{ }

void Game::clear() {

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
