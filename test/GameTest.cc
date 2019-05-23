#include "GameBuilder.h"
#include "FoundationBuilder.h"
#include "PileBuilder.h"
#include "CardBuilder.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class GameTest: public Test {
protected:
    GameBuilder gameBuilder;
    FoundationBuilder foundationBuilder;
    CardBuilder cardBuilder;
    PileBuilder pileBuilder;
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
    Game game = gameBuilder.clearStock().build();
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
    ASSERT_FALSE(game.getFoundations().at(&suit).empty());
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
    ASSERT_FALSE(game.getFoundations().at(&suit).empty());
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
    ASSERT_FALSE(game.getFoundations().at(&suit).empty());
    EXPECT_THAT(game.getFoundations().at(&suit).peek(), Eq(card));
}

TEST_F(GameTest, moveFromWasteToStockWithoutError) {
    Game game = gameBuilder.
        clearStock().
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
        build();

    auto* error = game.moveFromWasteToStock();
    EXPECT_THAT(error, Eq(&Error::NO_EMPTY_STOCK));
}

TEST_F(GameTest, moveFromWasteToStockWhenWasteIsEmpty) {
    Game game = gameBuilder.clearStock().build();

    auto* error = game.moveFromWasteToStock();
    EXPECT_THAT(error, Eq(&Error::EMPTY_WASTE));
}

TEST_F(GameTest, moveFromWasteToPileWhenWasteIsEmpty) {
    Game game = gameBuilder.build();

    auto* error = game.moveFromWasteToPile(0);
    EXPECT_THAT(error, Eq(&Error::EMPTY_WASTE));
}

TEST_F(GameTest, moveFromWasteToPileWithErrorNoFit) {
    int pileNumber = 0;
    Game game = gameBuilder.
        pile(pileNumber, pileBuilder.
            number(pileNumber).
            withCard(cardBuilder.suit(Suit::DIAMONDS).facedUp(true).number(Number::EIGHT).build()).
            build()).
        addToWaste(cardBuilder.suit(Suit::CLOVERS).number(Number::SIX).build()).
        build();

    auto* error = game.moveFromWasteToPile(pileNumber);
    EXPECT_THAT(error, Eq(&Error::NO_FIT_PILE));
}

TEST_F(GameTest, moveFromWasteToPileEmptyPile) {
    Card card = cardBuilder.suit(Suit::DIAMONDS).facedUp(true).number(Number::SIX).build();
    Game game = gameBuilder.
        addToWaste(card).
        build();

    auto* error = game.moveFromWasteToPile(0);
    EXPECT_THAT(error, IsNull());
    ASSERT_FALSE(game.getPiles().front().empty());
    EXPECT_THAT(game.getPiles().front().peek(), Eq(card));
}

TEST_F(GameTest, moveFromWasteToPileWithSuccess) {
    Card card = cardBuilder.suit(Suit::DIAMONDS).facedUp(true).number(Number::SIX).build();
    Game game = gameBuilder.
        pile(0, pileBuilder.
            number(0).
            withCard(cardBuilder.suit(Suit::CLOVERS).facedUp(true).number(Number::SEVEN).build()).
            build()).
        addToWaste(card).
        build();

    auto* error = game.moveFromWasteToPile(0);
    EXPECT_THAT(error, IsNull());
    ASSERT_FALSE(game.getPiles().front().empty());
    EXPECT_THAT(game.getPiles().front().peek(), Eq(card));
}

TEST_F(GameTest, moveFromFoundationToPileEmptyFoundation) {
    Game game;

    auto* error = game.moveFromFoundationToPile(&Suit::CLOVERS, 0);
    EXPECT_THAT(error, Eq(&Error::EMPTY_FOUNDATION));
}

TEST_F(GameTest, moveFromFoundationToPileNoFit) {
    const Suit& suit = Suit::DIAMONDS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::SIX).build();
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(card).
            build()).
        pile(0, pileBuilder.
            number(0).
            withCard(cardBuilder.suit(Suit::CLOVERS).facedUp(true).number(Number::EIGHT).build()).
            build()).
        build();

    auto* error = game.moveFromFoundationToPile(&suit, 0);
    EXPECT_THAT(error, Eq(&Error::NO_FIT_PILE));
}

TEST_F(GameTest, moveFromFoundationToPileSucess) {
    const Suit& suit = Suit::HEARTS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::SIX).build();
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(card).
            build()).
        pile(0, pileBuilder.
            number(0).
            withCard(cardBuilder.suit(Suit::PIKES).facedUp(true).number(Number::SEVEN).build()).
            build()).
        build();

    auto* error = game.moveFromFoundationToPile(&suit, 0);
    EXPECT_THAT(error, IsNull());
    ASSERT_FALSE(game.getPiles().front().empty());
    EXPECT_THAT(game.getPiles().front().peek(), Eq(card));
    EXPECT_TRUE(game.getFoundations().at(&suit).empty());
}

TEST_F(GameTest, moveFromPileToFoundationEmptyPile) {
    Game game;

    auto* error = game.moveFromPileToFoundation(0, &Suit::CLOVERS);
    EXPECT_THAT(error, Eq(&Error::EMPTY_PILE));
}

TEST_F(GameTest, moveFromPileToFoundationNoFit) {
    const Suit& suit = Suit::DIAMONDS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::SIX).build();
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(cardBuilder.facedUp(true).number(Number::EIGHT).build()).
            build()).
        pile(0, pileBuilder.
            number(0).
            withCard(card).
            build()).
        build();

    auto* error = game.moveFromFoundationToPile(&suit, 0);
    EXPECT_THAT(error, Eq(&Error::NO_FIT_FOUNDATION));
}

TEST_F(GameTest, moveFromPileToFoundationSuccess) {
    const Suit& suit = Suit::HEARTS;
    Card card = cardBuilder.suit(suit).facedUp(true).number(Number::TWO).build();
    Game game = gameBuilder.
        foundation(suit, foundationBuilder.
            suit(suit).
            withCard(cardBuilder.facedUp(true).number(Number::THREE).build()).
            build()).
        pile(0, pileBuilder.
            number(0).
            withCard(card).
            build()).
        build();

    auto* error = game.moveFromFoundationToPile(&suit, 0);
    EXPECT_THAT(error, IsNull());
    ASSERT_FALSE(game.getFoundations().at(&suit).empty());
    EXPECT_THAT(game.getFoundations().at(&suit).peek(), Eq(card));
    EXPECT_TRUE(game.getPiles().front().empty());
}
