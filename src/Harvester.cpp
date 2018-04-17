//
// Created by Henry Warren on 4/16/18.
//
#include <iostream>
#include <string>

#include "UrlFrontier.h"
#include "PageGrabber.h"
#include "Parser.h"

#define DEFAULT_SEED_URL "https://university.graduateshotline.com/ubystate.html"

using namespace std;

void run(string);

int main (int argc, char**argv) {
    switch(argc) {
        case 1:
            run(DEFAULT_SEED_URL);
            break;
        case 2:
            run(argv[1]);
            break;
        default:
            return 1;
    }
    return 0;
}

void run(string seedurl) {
    UrlFrontier urlfront = UrlFrontier();
    urlfront.add_url(seedurl);
    PageGrabber pgrabber = PageGrabber();

    while (!urlfront.is_empty()) {
        pgrabber.fetch_page(urlfront.next_url());
    }
}