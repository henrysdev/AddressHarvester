//
// Created by crackerjacks on 4/16/18.
//

#ifndef ENTRY_PAGEGRABBER_H
#define ENTRY_PAGEGRABBER_H

#include "Parser.h"
#include <string>

class PageGrabber {
private:
    Parser * parser = NULL;
public:
    PageGrabber(Parser&);
    void fetch_page(std::string);
    std::string base_url(std::string);
};


#endif //ENTRY_PAGEGRABBER_H
