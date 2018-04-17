//
// Created by Henry Warren on 4/17/18.
//

#ifndef ENTRY_URLGUESSER_H
#define ENTRY_URLGUESSER_H

#include <string>

class UrlGuesser {
private:
    std::string currurl;
public:
    UrlGuesser();
    void gen_next();
};


#endif //ENTRY_URLGUESSER_H
