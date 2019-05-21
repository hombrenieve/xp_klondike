#include "StockBuilder.h"


StockBuilder::StockBuilder()
{ }

StockBuilder& StockBuilder::withCard(const Card& card) {
    cards.push_back(card);
    return *this;
}

Stock StockBuilder::build() {
    Stock stock;
    for(const auto& card: cards) {
        stock.push(card);
    }
    return stock;
}