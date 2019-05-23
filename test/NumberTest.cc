#include "Number.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(NumberTest, FindReturnsACE) {
    EXPECT_EQ(&Number::ACE, Number::find(1));
}

TEST(NumberTest, FindReturnsKING) {
    EXPECT_EQ(&Number::KING, Number::find(13));
}

TEST(NumberTest, FindUnknownNumberNegativeReturnsNull) {
    EXPECT_THAT(Number::find(-1), IsNull());
}

TEST(NumberTest, FindUnknownNumberHigherReturnsNull) {
    EXPECT_THAT(Number::find(50), IsNull());
}
