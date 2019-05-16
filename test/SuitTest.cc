#include "Suit.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(SuitTest, FindReturnsHearts) {
    ASSERT_EQ(&Suit::HEARTS, Suit::find('h'));
}
 
TEST(SuitTest, InitialNotNull) {
    ASSERT_THAT(Suit::initials(), NotNull());
}

