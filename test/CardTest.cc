#include "Suit.h"
#include "CardBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(CardTest, FlipCard) {
    Card faceDown = CardBuilder().build();

    EXPECT_FALSE(faceDown.isFacedUp());
    EXPECT_EQ(&faceDown, faceDown.flip());
    EXPECT_TRUE(faceDown.isFacedUp());
    EXPECT_EQ(&faceDown, faceDown.flip());
    EXPECT_FALSE(faceDown.isFacedUp());
}



TEST(CardTest, isNextToCorrect) {
    Card ace = CardBuilder().number(Number::ACE).build();
    Card two = CardBuilder().number(Number::TWO).build();

    EXPECT_TRUE(two.isNextTo(ace));
}

TEST(CardTest, isNextToNotCorrect) {
    Card ace = CardBuilder().number(Number::ACE).build();
    Card two = CardBuilder().number(Number::TWO).build();

    EXPECT_FALSE(ace.isNextTo(two));
}