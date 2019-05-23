#include "Stock.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class StockTest: public Test {
protected:
    Stock stock;
    static int stockSize() {
        return Number::DECK_LENGTH*Suit::initials().size();
    }
};

TEST_F(StockTest, takeTopWithEmptyStock) {
    EXPECT_FALSE(stock.empty());
    auto top = stock.takeTop(stockSize());
    EXPECT_TRUE(stock.empty());

    top = stock.takeTop(3);

    EXPECT_TRUE(top.empty());
    EXPECT_TRUE(stock.empty());
}

TEST_F(StockTest, takeTopAllStock) {
    EXPECT_FALSE(stock.empty());

    auto top = stock.takeTop(stockSize());

    EXPECT_THAT(top, SizeIs(stockSize()));
    EXPECT_TRUE(stock.empty());
}

TEST_F(StockTest, takeTopMoreThanInStock) {
    EXPECT_FALSE(stock.empty());

    auto top = stock.takeTop(stockSize()+1);

    EXPECT_THAT(top, SizeIs(stockSize()));
    EXPECT_TRUE(stock.empty());
}

TEST_F(StockTest, takeSomeStock) {
    EXPECT_FALSE(stock.empty());

    auto top = stock.takeTop(3);

    EXPECT_THAT(top, SizeIs(3));
    EXPECT_FALSE(stock.empty());
}