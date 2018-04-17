//
// Created by crackerjacks on 4/16/18.
//

#ifndef ENTRY_URLFRONTIER_H
#define ENTRY_URLFRONTIER_H

#include <string>
#include <queue>

using namespace std;

class UrlFrontier {
private:
    queue<string> queue_ds;
public:
    UrlFrontier();
    bool is_empty();
    void add_url(string);
    string next_url();
};


#endif //ENTRY_URLFRONTIER_H
