#include "Error.h"

Error Error::EMPTY_STOCK("Empty stock"),
    Error::EMPTY_WASTE("Empty waste"),
    Error::EMPTY_FOUNDATION("Empty foundation"),
    Error::EMPTY_PILE("Empty pile"),
    Error::NO_EMPTY_STOCK("Stock is not empty"),
    Error::NO_FIT_FOUNDATION("Foundation not empty"),
    Error::NO_FIT_PILE("Pile not empty"),
    Error::SAME_PILE("Same pile"),
    Error::NO_ENOUGH_CARDS_PILE("Not enough cards in pile");

Error::Error(const std::string& message) :
    message(message)
{ }

const std::string& Error::getMessage() {
    return this->message;
}
