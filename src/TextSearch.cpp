//
// Created by Henry Warren on 4/17/18.
//

#include "TextSearch.h"
#include <regex>
#include <sstream>
#include <iostream>

#define EMAIL_REGEX "[\\dA-z-_]+(\\.[\\dA-z-_]+)*@[\\dA-z-_]+(\\.[\\dA-z-_]+)*"

std::vector<std::string> TextSearch::find_emails(std::string pagetext) {
    std::regex emailreg(EMAIL_REGEX);
    std::vector<std::string> found_emails;

    //line by line regex
    std::istringstream f(pagetext);
    std::string line;
    while (std::getline(f, line)) {
        const std::string myline = (std::string) line;
        std::smatch match;
        if (std::regex_search(myline.begin(), myline.end(), match, emailreg))
        {
            std::cout << match[0] << std::endl;
            found_emails.push_back(match[0]);
        }
    }
    return found_emails;
}