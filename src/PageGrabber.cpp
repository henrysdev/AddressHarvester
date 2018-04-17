//
// Created by crackerjacks on 4/16/18.
//

#include "PageGrabber.h"
#include "utils/HTTPDownloader.h"
#include <iostream>


PageGrabber::PageGrabber(Parser& p) {
    parser = &p;
}

void PageGrabber::fetch_page(std::string url) {
    HTTPDownloader downloader;
    std::string content = downloader.download(url);
    parser->parse_html(content, url);
}