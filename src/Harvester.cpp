//
// Created by Henry Warren on 4/16/18.
//
#include <iostream>
#include <chrono>
#include <thread>
#include <string>

#include "UrlFrontier.h"
#include "PageGrabber.h"
#include "UrlFilter.h"
#include "Parser.h"

#define DEFAULT_SEED_URL "https://github.com/henrysdev" //"https://s2.smu.edu/~fmoore/"
#define CRAWL_DELAY_MS 1000

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
    UrlFilter urlfilter = UrlFilter();
    Parser parser = Parser(urlfront, urlfilter);
    PageGrabber pgrabber = PageGrabber(parser);

    while (!urlfront.is_empty()) {
        std::string next = urlfront.next_url();
        std::cout << next << std::endl;
        pgrabber.fetch_page(next);
        std::this_thread::sleep_for(std::chrono::milliseconds(CRAWL_DELAY_MS));
    }
}