//
// Created by Henry Warren on 4/17/18.
//

#include "UrlFilter.h"

#include <iostream>

UrlFilter::UrlFilter() {

}

bool UrlFilter::is_valid(std::string url) {
    if (!visited.count(url)) {
        visited[url] = 1;
        return true;
    } else {
        return false;
    }
}