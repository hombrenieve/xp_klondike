#include "Suit.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(SuitTest, FindReturnsHearts) {
    EXPECT_EQ(&Suit::HEARTS, Suit::find('h'));
}

TEST(SuitTest, FindUnknownSuitReturnsNull) {
    EXPECT_THAT(Suit::find('x'), IsNull());
}

TEST(SuitTest, ColorOfPikes) {
    EXPECT_EQ(&Color::BLACK, Suit::PIKES.getColor());
}
 
TEST(SuitTest, InitialsNotEmpty) {
    EXPECT_THAT(Suit::initials(), Not(IsEmpty()));
}

TEST(SuitTest, InitialsAreCorrect) {
    EXPECT_THAT(Suit::initials(), UnorderedElementsAre('h', 'c', 'd', 'p'));
}

