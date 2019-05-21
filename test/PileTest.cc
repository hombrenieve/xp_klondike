#include "Pile.h"
#include "CardBuilder.h"
#include "PileBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

TEST(PileTest, getTopWithEmptyPile) {
    Pile pile = PileBuilder().build();

    auto top = pile.getTop(1);

    EXPECT_THAT(top, IsEmpty());
}

TEST(PileTest, getTopWithOneElement) {
    Pile pile = PileBuilder().withCard(CardBuilder().build()).build();

    auto top = pile.getTop(1);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_FALSE(pile.empty());
}

TEST(PileTest, getTopMoreElementsThanStored) {
    Pile pile = PileBuilder().withCard(CardBuilder().build()).build();

    auto top = pile.getTop(2);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_FALSE(pile.empty());
}

TEST(PileTest, fitsInWrongCardNumber) {
    Pile pile = PileBuilder().withCard(CardBuilder().suit(Suit::HEARTS).number(Number::SIX).facedUp(true).build()).build();

    EXPECT_FALSE(pile.fitsIn(CardBuilder().suit(Suit::CLOVERS).number(Number::EIGHT).facedUp(true).build()));
}

TEST(PileTest, fitsInWrongCardSuit) {
    Pile pile = PileBuilder().withCard(CardBuilder().suit(Suit::HEARTS).number(Number::SIX).facedUp(true).build()).build();

    EXPECT_FALSE(pile.fitsIn(CardBuilder().suit(Suit::HEARTS).number(Number::FIVE).facedUp(true).build()));
}

TEST(PileTest, fitsInCorrectCard) {
    Pile pile = PileBuilder().withCard(CardBuilder().suit(Suit::HEARTS).number(Number::SIX).facedUp(true).build()).build();

    EXPECT_TRUE(pile.fitsIn(CardBuilder().suit(Suit::CLOVERS).number(Number::FIVE).facedUp(true).build()));
}

TEST(PileTest, addToTopReallyAdds) {
    Pile pile = PileBuilder().build();
    EXPECT_TRUE(pile.empty());

    std::list<Card> cards { CardBuilder().facedUp(true).build(), CardBuilder().facedUp(true).build() };

    pile.addToTop(cards);
    EXPECT_FALSE(pile.empty());
    EXPECT_EQ(2, pile.getNumberOfFaceUpCards());
}

TEST(PileTest, removeTopReallyRemoves) {
    Pile pile = PileBuilder().withCard(CardBuilder().build()).build();
    EXPECT_FALSE(pile.empty());

    pile.removeTop(1);
    EXPECT_TRUE(pile.empty());
}

TEST(PileTest, removeTopCardFlipped) {
    Pile pile = PileBuilder().withCard(CardBuilder().build()).withCard(CardBuilder().facedUp(true).build()).build();
    EXPECT_EQ(1, pile.getNumberOfFaceUpCards());

    pile.removeTop(1);
    EXPECT_EQ(1, pile.getNumberOfFaceUpCards());
    EXPECT_TRUE(pile.peek().isFacedUp());
}

TEST(PileTest, getFaceUpCardsWhenThereArent) {
    Pile pile = PileBuilder().withCard(CardBuilder().build()).build();

    EXPECT_EQ(0, pile.getNumberOfFaceUpCards());
}

TEST(PileTest, getFaceUpCardsWhenThereAre) {
    Pile pile = PileBuilder().withCard(CardBuilder().facedUp(true).build()).build();

    EXPECT_EQ(1, pile.getNumberOfFaceUpCards());
}