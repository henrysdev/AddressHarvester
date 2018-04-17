//
// Created by Henry Warren on 4/17/18.
//

#ifndef ENTRY_URLFILTER_H
#define ENTRY_URLFILTER_H

#include <string>
#include <unordered_map>

class UrlFilter {
private:
    std::unordered_map<std::string,int> visited;
public:
    UrlFilter();
    bool is_valid(std::string url);
};


#endif //ENTRY_URLFILTER_H