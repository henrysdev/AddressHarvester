//
// Created by crackerjacks on 4/16/18.
//

#ifndef ENTRY_PAGEGRABBER_H
#define ENTRY_PAGEGRABBER_H

#include "Parser.h"
#include <string>

using namespace std;

class PageGrabber {
private:
    Parser * parser = NULL;
public:
    PageGrabber(Parser&);
    void fetch_page(string);
};


#endif //ENTRY_PAGEGRABBER_H
