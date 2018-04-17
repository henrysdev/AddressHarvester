//
// Created by crackerjacks on 4/16/18.
//

#include "PageGrabber.h"
#include "utils/HTTPDownloader.h"
#include <iostream>


PageGrabber::PageGrabber(Parser& p) {
    parser = &p;
}

std::string PageGrabber::base_url(std::string url) {
    int slashcount = 0;
    std::string base = "";
    for (int i = 0; i < url.length(); i++) {
        base += url[i];
        if (url[i] == '/')
            slashcount++;
        if (slashcount == 3)
            return base;
    }
}

void PageGrabber::fetch_page(std::string url) {
    HTTPDownloader downloader;
    std::string content = downloader.download(url);
    std::string baseurl = base_url(url);
    parser->parse_html(content, baseurl);
}