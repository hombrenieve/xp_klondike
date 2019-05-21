#include "Foundation.h"
#include "CardBuilder.h"
#include "FoundationBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;


class FoundationTest: public Test {
protected:
    FoundationBuilder foundationBuilder;
    CardBuilder cardBuilder;
};

TEST_F(FoundationTest, fitsInWrongCardNumber) {
    foundationBuilder.suit(Suit::HEARTS);
    cardBuilder.suit(Suit::HEARTS).facedUp(true);
    Foundation foundation = foundationBuilder.withCard(cardBuilder.number(Number::KING).build()).build();

    EXPECT_FALSE(foundation.fitsIn(cardBuilder.number(Number::EIGHT).build()));
}

TEST_F(FoundationTest, fitsInWrongCardSuit) {
    foundationBuilder.suit(Suit::CLOVERS);
    cardBuilder.suit(Suit::CLOVERS).facedUp(true);
    Foundation foundation = foundationBuilder.withCard(cardBuilder.number(Number::KING).build()).build();

    EXPECT_FALSE(foundation.fitsIn(cardBuilder.suit(Suit::HEARTS).number(Number::QUEEN).build()));
}

TEST_F(FoundationTest, fitsInCorrectCard) {
    foundationBuilder.suit(Suit::PIKES);
    cardBuilder.suit(Suit::PIKES).facedUp(true);
    Foundation foundation = foundationBuilder.withCard(cardBuilder.number(Number::KING).build()).build();

    EXPECT_TRUE(foundation.fitsIn(cardBuilder.number(Number::QUEEN).build()));
}

TEST_F(FoundationTest, isCompleteWhenEmpty) {
    Foundation foundation = foundationBuilder.build();

    EXPECT_FALSE(foundation.isComplete());
}

TEST_F(FoundationTest, isCompleteWhenNot) {
    foundationBuilder.suit(Suit::PIKES);
    cardBuilder.suit(Suit::PIKES).facedUp(true);
    Foundation foundation = foundationBuilder.
        withCard(cardBuilder.number(Number::KING).build()).
        withCard(cardBuilder.number(Number::QUEEN).build()).
        withCard(cardBuilder.number(Number::JACK).build()).
        build();

    EXPECT_FALSE(foundation.isComplete());
}

TEST_F(FoundationTest, isCompleteCorrect) {
    Foundation foundation = foundationBuilder.suit(Suit::HEARTS).fullSuit().build();

    EXPECT_TRUE(foundation.isComplete());
}