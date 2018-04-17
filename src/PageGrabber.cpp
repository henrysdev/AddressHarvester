//
// Created by crackerjacks on 4/16/18.
//

#include "PageGrabber.h"
#include "utils/HTTPDownloader.h"
#include <iostream>

using namespace std;

PageGrabber::PageGrabber(Parser& p) {
    parser = &p;
}

void PageGrabber::fetch_page(string url) {
    HTTPDownloader downloader;
    string content = downloader.download(url);
    parser->parse_html(content, url);
}