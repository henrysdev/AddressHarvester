//
// Created by crackerjacks on 4/16/18.
//

#include "UrlFrontier.h"

UrlFrontier::UrlFrontier() {
}

bool UrlFrontier::is_empty() {
    return queue_ds.empty();
}

void UrlFrontier::add_url(string url) {
    queue_ds.push(url);
}

string UrlFrontier::next_url() {
    string next = queue_ds.front();
    queue_ds.pop();
    return next;
}