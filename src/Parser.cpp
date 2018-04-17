//
// Created by crackerjacks on 4/16/18.
//
#include <string>
#include <iostream>
#include <gumbo.h>

#include "Parser.h"

using namespace std;

Parser::Parser() {

}

// https://github.com/google/gumbo-parser
void Parser::parse_html(string contents) {
    GumboOutput* output = gumbo_parse(contents.c_str());
    // do stuff with output->root
    cout << output->root << endl;

    gumbo_destroy_output(&kGumboDefaultOptions, output);
}