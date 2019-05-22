#ifndef _ERROR_H_
#define _ERROR_H_

#include <string>

class Error {
public:
    static Error EMPTY_STOCK,
        EMPTY_WASTE,
        EMPTY_FOUNDATION,
        EMPTY_PILE,
        NO_EMPTY_STOCK,
        NO_FIT_FOUNDATION,
        NO_FIT_PILE,
        SAME_PILE,
        NO_ENOUGH_CARDS_PILE;


    const std::string& getMessage();
private:
    Error(const std::string& message);

    std::string message;
};

#endif
