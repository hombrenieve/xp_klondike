#include "Stock.h"
#include "StockBuilder.h"
#include "CardBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(StockTest, takeTopWithEmptyStock) {
    Stock stock;

    auto top = stock.takeTop(1);

    EXPECT_THAT(top, IsEmpty());
    EXPECT_TRUE(stock.empty());
}

TEST(StockTest, takeTopExactlyInStock) {
    Stock stock = StockBuilder().withCard(CardBuilder().build()).build();

    auto top = stock.takeTop(1);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_TRUE(stock.empty());
}

TEST(StockTest, takeTopMoreThanInStock) {
    Stock stock = StockBuilder().withCard(CardBuilder().build()).build();

    auto top = stock.takeTop(2);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_TRUE(stock.empty());
}

