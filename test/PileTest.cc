#include "Pile.h"
#include "CardBuilder.h"
#include "PileBuilder.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using namespace testing;

class PileTest: public Test {
protected:
    PileBuilder pileBuilder;
    CardBuilder cardBuilder;
};

TEST_F(PileTest, getTopWithEmptyPile) {
    Pile pile = pileBuilder.build();

    auto top = pile.getTop(1);

    EXPECT_THAT(top, IsEmpty());
}

TEST_F(PileTest, getTopWithOneElement) {
    Pile pile = pileBuilder.withCard(cardBuilder.build()).build();

    auto top = pile.getTop(1);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_FALSE(pile.empty());
}

TEST_F(PileTest, getTopMoreElementsThanStored) {
    Pile pile = pileBuilder.withCard(cardBuilder.build()).build();

    auto top = pile.getTop(2);

    EXPECT_THAT(top, SizeIs(1));
    EXPECT_FALSE(pile.empty());
}

TEST_F(PileTest, fitsInWrongCardNumber) {
    Pile pile = pileBuilder.withCard(cardBuilder.suit(Suit::HEARTS).number(Number::SIX).facedUp(true).build()).build();

    EXPECT_FALSE(pile.fitsIn(cardBuilder.suit(Suit::CLOVERS).number(Number::EIGHT).facedUp(true).build()));
}

TEST_F(PileTest, fitsInWrongCardSuit) {
    Pile pile = pileBuilder.withCard(cardBuilder.suit(Suit::HEARTS).number(Number::SIX).facedUp(true).build()).build();

    EXPECT_FALSE(pile.fitsIn(cardBuilder.suit(Suit::HEARTS).number(Number::FIVE).facedUp(true).build()));
}

TEST_F(PileTest, fitsInCorrectCard) {
    Pile pile = pileBuilder.withCard(cardBuilder.suit(Suit::HEARTS).number(Number::SIX).facedUp(true).build()).build();

    EXPECT_TRUE(pile.fitsIn(cardBuilder.suit(Suit::CLOVERS).number(Number::FIVE).facedUp(true).build()));
}

TEST_F(PileTest, addToTopReallyAdds) {
    Pile pile = pileBuilder.build();
    EXPECT_TRUE(pile.empty());

    std::list<Card> cards { cardBuilder.facedUp(true).build(), cardBuilder.facedUp(true).build() };

    pile.addToTop(cards);
    EXPECT_FALSE(pile.empty());
    EXPECT_EQ(2, pile.getNumberOfFaceUpCards());
}

TEST_F(PileTest, removeTopReallyRemoves) {
    Pile pile = pileBuilder.withCard(cardBuilder.build()).build();
    EXPECT_FALSE(pile.empty());

    pile.removeTop(1);
    EXPECT_TRUE(pile.empty());
}

TEST_F(PileTest, removeTopCardFlipped) {
    Pile pile = pileBuilder.withCard(cardBuilder.build()).withCard(cardBuilder.facedUp(true).build()).build();
    EXPECT_EQ(1, pile.getNumberOfFaceUpCards());

    pile.removeTop(1);
    EXPECT_EQ(1, pile.getNumberOfFaceUpCards());
    EXPECT_TRUE(pile.peek().isFacedUp());
}

TEST_F(PileTest, getFaceUpCardsWhenThereArent) {
    Pile pile = pileBuilder.withCard(cardBuilder.build()).build();

    EXPECT_EQ(0, pile.getNumberOfFaceUpCards());
}

TEST_F(PileTest, getFaceUpCardsWhenThereAre) {
    Pile pile = pileBuilder.withCard(cardBuilder.facedUp(true).build()).build();

    EXPECT_EQ(1, pile.getNumberOfFaceUpCards());
}