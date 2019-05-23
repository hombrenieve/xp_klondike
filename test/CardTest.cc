#include "Suit.h"
#include "CardBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class CardTest: public Test {
protected:
    CardBuilder cardBuilder;
};

TEST_F(CardTest, FlipCard) {
    Card card = cardBuilder.build();

    EXPECT_FALSE(card.isFacedUp());
    EXPECT_EQ(&card, card.flip());
    EXPECT_TRUE(card.isFacedUp());
    EXPECT_EQ(&card, card.flip());
    EXPECT_FALSE(card.isFacedUp());
}

TEST_F(CardTest, isNextToCorrect) {
    Card ace = cardBuilder.number(Number::ACE).build();
    Card two = cardBuilder.number(Number::TWO).build();

    EXPECT_TRUE(two.isNextTo(ace));
}

TEST_F(CardTest, isNextToNotCorrect) {
    Card ace = cardBuilder.number(Number::ACE).build();
    Card two = cardBuilder.number(Number::TWO).build();

    EXPECT_FALSE(ace.isNextTo(two));
}