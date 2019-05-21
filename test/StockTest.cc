#include "Stock.h"
#include "StockBuilder.h"
#include "CardBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class StockTest: public Test {
protected:
    StockBuilder stockBuilder;
    CardBuilder cardBuilder;
};

TEST_F(StockTest, takeTopWithEmptyStock) {
    Stock stock;

    auto top = stock.takeTop(1);

    EXPECT_THAT(top, IsEmpty());
    EXPECT_TRUE(stock.empty());
}

TEST_F(StockTest, takeTopExactlyInStock) {
    Stock stock = stockBuilder.withCard(cardBuilder.build()).build();

    auto top = stock.takeTop(1);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_TRUE(stock.empty());
}

TEST_F(StockTest, takeTopMoreThanInStock) {
    Stock stock = stockBuilder.withCard(cardBuilder.build()).build();

    auto top = stock.takeTop(2);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_TRUE(stock.empty());
}

