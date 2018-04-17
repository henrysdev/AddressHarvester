//
// Created by crackerjacks on 4/16/18.
//

#include "PageGrabber.h"
#include "utils/HTTPDownloader.h"
#include <iostream>

using namespace std;

PageGrabber::PageGrabber() {
    parser = Parser();
}

void PageGrabber::fetch_page(string) {
    HTTPDownloader downloader;
    string content = downloader.download("https://stackoverflow.com");
    parser.parse_html(content);
}