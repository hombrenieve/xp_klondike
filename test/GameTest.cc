#include "GameBuilder.h"
#include "FoundationBuilder.h"
#include "StockBuilder.h"
#include "CardBuilder.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class GameTest: public Test {
protected:
    GameBuilder gameBuilder;
    FoundationBuilder foundationBuilder;
    CardBuilder cardBuilder;
    StockBuilder stockBuilder;
};

TEST_F(GameTest, isFinishedWhenNotFinished) {
    Game game = gameBuilder.foundation(Suit::HEARTS, foundationBuilder.suit(Suit::HEARTS).fullSuit().build()).build();

    EXPECT_FALSE(game.isFinished());
}

TEST_F(GameTest, isFinishedWhenFinished) {
    Game game = gameBuilder.
        foundation(Suit::HEARTS, foundationBuilder.suit(Suit::HEARTS).fullSuit().build()).
        foundation(Suit::DIAMONDS, foundationBuilder.suit(Suit::DIAMONDS).fullSuit().build()).
        foundation(Suit::CLOVERS, foundationBuilder.suit(Suit::CLOVERS).fullSuit().build()).
        foundation(Suit::PIKES, foundationBuilder.suit(Suit::PIKES).fullSuit().build()).
        build();

    EXPECT_TRUE(game.isFinished());
}

TEST_F(GameTest, clearRemovesFinishedState) {
    Game game = gameBuilder.
        foundation(Suit::HEARTS, foundationBuilder.suit(Suit::HEARTS).fullSuit().build()).
        foundation(Suit::DIAMONDS, foundationBuilder.suit(Suit::DIAMONDS).fullSuit().build()).
        foundation(Suit::CLOVERS, foundationBuilder.suit(Suit::CLOVERS).fullSuit().build()).
        foundation(Suit::PIKES, foundationBuilder.suit(Suit::PIKES).fullSuit().build()).
        build();
    EXPECT_TRUE(game.isFinished());

    game.clear();
    EXPECT_FALSE(game.isFinished());
}

TEST_F(GameTest, moveFromStockToWasteWithoutError) {
    Game game;
    EXPECT_FALSE(game.getStock().empty());
    EXPECT_TRUE(game.getWaste().empty());

    auto* error = game.moveFromStockToWaste();
    EXPECT_THAT(error, IsNull());
    EXPECT_FALSE(game.getWaste().empty());
}

TEST_F(GameTest, moveFromStockToWasteWhenStockIsEmpty) {
    Game game = gameBuilder.build();
    EXPECT_TRUE(game.getStock().empty());
    EXPECT_TRUE(game.getWaste().empty());

    auto* error = game.moveFromStockToWaste();
    EXPECT_THAT(error, Eq(&Error::EMPTY_STOCK));
}

TEST_F(GameTest, moveFromWasteToFoundationWithoutError) {
    const Suit& suit = Suit::HEARTS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::JACK).build();
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(cardBuilder.number(Number::KING).build()).
            withCard(cardBuilder.number(Number::QUEEN).build()).
            build()).
        addToWaste(card).
        build();

    auto* error = game.moveFromWasteToFoundation(&suit);
    EXPECT_THAT(error, IsNull());
    EXPECT_THAT(game.getFoundations().at(&suit).peek(), Eq(card));
}

TEST_F(GameTest, moveFromWasteToFoundationWithoutErrorEmptyFoundation) {
    const Suit& suit = Suit::CLOVERS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::KING).build();
    Game game = gameBuilder.
        addToWaste(card).
        build();

    auto* error = game.moveFromWasteToFoundation(&suit);
    EXPECT_THAT(error, IsNull());
    EXPECT_THAT(game.getFoundations().at(&suit).peek(), Eq(card));
}

TEST_F(GameTest, moveFromWasteToFoundationWithErrorEmpty) {
    const Suit& suit = Suit::HEARTS;
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(cardBuilder.suit(suit).facedUp(true).number(Number::KING).build()).
            build()).
        build();

    auto* error = game.moveFromWasteToFoundation(&suit);
    EXPECT_THAT(error, Eq(&Error::EMPTY_WASTE));
}

TEST_F(GameTest, moveFromWasteToFoundationWithErrorNoFit) {
    const Suit& suit = Suit::CLOVERS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::KING).build();
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(card).
            build()).
        addToWaste(cardBuilder.number(Number::JACK).build()).
        build();

    auto* error = game.moveFromWasteToFoundation(&suit);
    EXPECT_THAT(error, Eq(&Error::NO_FIT_FOUNDATION));
    EXPECT_THAT(game.getFoundations().at(&suit).peek(), Eq(card));
}

TEST_F(GameTest, moveFromWasteToStockWithoutError) {
    Game game = gameBuilder.
        addToWaste(cardBuilder.facedUp(true).build()).
        build();
    EXPECT_TRUE(game.getStock().empty());

    auto* error = game.moveFromWasteToStock();
    EXPECT_THAT(error, IsNull());
    EXPECT_FALSE(game.getStock().empty());
    EXPECT_TRUE(game.getWaste().empty());
}

TEST_F(GameTest, moveFromWasteToStockWhenStockIsNotEmpty) {
    Game game = gameBuilder.
        addToWaste(cardBuilder.facedUp(true).build()).
        stock(stockBuilder.withCard(cardBuilder.number(Number::SIX).build()).build()).
        build();

    auto* error = game.moveFromWasteToStock();
    EXPECT_THAT(error, Eq(&Error::NO_EMPTY_STOCK));
}

TEST_F(GameTest, moveFromWasteToStockWhenWasteIsEmpty) {
    Game game = gameBuilder.build();

    auto* error = game.moveFromWasteToStock();
    EXPECT_THAT(error, Eq(&Error::EMPTY_WASTE));
}
