//
// Created by crackerjacks on 4/16/18.
//

#ifndef ENTRY_PARSER_H
#define ENTRY_PARSER_H

#include <string>
#include <vector>

#include "UrlFrontier.h"
#include "UrlFilter.h"
#include "TextSearch.h"
#include "libs/gumbo-parser/src/gumbo.h"

class Parser {
private:
    UrlFrontier * urlfrontier = NULL;
    UrlFilter * urlfilter = NULL;
    TextSearch textsearch;
    std::vector<std::string> foundlinks;
    void search_for_links(GumboNode*);
    std::string cleantext(GumboNode*);
public:
    Parser(UrlFrontier&, UrlFilter&);
    void parse_html(std::string, std::string);
};


#endif //ENTRY_PARSER_H
