//
// Created by Henry Warren on 4/17/18.
//

#include "UrlGuesser.h"
#include <iostream>

#define USERNAME_MAX_LEN 20

UrlGuesser::UrlGuesser() {
    currurl = "a";
}

void UrlGuesser::gen_next() {
    int i = 0;
    while (i < USERNAME_MAX_LEN) {
        std::cout << currurl << std::endl;
        int len = currurl.length();
        // if last char in string is between 'a' and 'z'
        if (currurl[len-1] >= 96 && currurl[len-1] < 122) {
            currurl[len-1]++;
        } else if (currurl[len-1] == 122) {
            currurl[len-1] = 48;
        } else if (currurl[len-1] >= 48 && currurl[len-1] < 57) {
            currurl[len-1]++;
        } else if (currurl[len-1] == 57) {
            currurl += 'a';
            i++;
        }
    }
}