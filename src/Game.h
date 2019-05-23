#ifndef _GAME_H_
#define _GAME_H_

#include "Error.h"
#include "Suit.h"
#include "Stock.h"
#include "Waste.h"
#include "Foundation.h"
#include "Pile.h"

#include <map>
#include <list>

class Game {
public:
    static const int NUMBER_OF_PILES = 7;

    Game();
    void clear();
    bool isFinished() const;
    const Error* moveFromStockToWaste();
    const Error* moveFromWasteToFoundation(const Suit* suit);
    const Error* moveFromWasteToStock();
    const Error* moveFromWasteToPile(int pileIndex);
    const Error* moveFromFoundationToPile(const Suit* suit, int pileIndex);
    const Error* moveFromPileToFoundation(int pileIndex, const Suit* suit);
    const Error* moveFromPileToPile(int originIndex, int destinationIndex, int numberOfCards);
    Stock& getStock();
    Waste& getWaste();
    std::map<const Suit*, Foundation>& getFoundations();
    std::list<Pile>& getPiles();

private:
    std::map<const Suit*, Foundation> foundations;
    std::list<Pile> piles;
    Waste waste;
    Stock stock;

    void initializeFoundations();
    void initializePiles();

};

#endif
