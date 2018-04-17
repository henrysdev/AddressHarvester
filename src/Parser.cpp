//
// Created by crackerjacks on 4/16/18.
//
#include <string>
#include <iostream>

#include "Parser.h"
#include "libs/gumbo-parser/src/gumbo.h"

Parser::Parser(UrlFrontier& ufront, UrlFilter& ufilt) {
    urlfrontier = &ufront;
    urlfilter = &ufilt;
    textsearch = TextSearch();
}


// https://github.com/google/gumbo-parser
std::string Parser::cleantext(GumboNode* node) {
    if (node->type == GUMBO_NODE_TEXT) {
        return std::string(node->v.text.text);
    } else if (node->type == GUMBO_NODE_ELEMENT &&
               node->v.element.tag != GUMBO_TAG_SCRIPT &&
               node->v.element.tag != GUMBO_TAG_STYLE) {
        std::string contents = "";
        GumboVector* children = &node->v.element.children;
        for (unsigned int i = 0; i < children->length; ++i) {
            const std::string text = cleantext((GumboNode*) children->data[i]);
            if (i != 0 && !text.empty()) {
                contents.append(" ");
            }
            contents.append(text);
        }
        return contents;
    } else {
        return "";
    }
}


// https://github.com/google/gumbo-parser
void Parser::search_for_links(GumboNode* node) {
    if (node->type != GUMBO_NODE_ELEMENT) {
        return;
    }

    GumboAttribute* href;
    if (node->v.element.tag == GUMBO_TAG_A &&
        (href = gumbo_get_attribute(&node->v.element.attributes, "href"))) {
        std::string foundurl = href->value;
        std::string sub = "http";
        // TODO allow relative path hrefs (must convert them to absolute links)
        if (!foundurl.compare(0,sub.length(),sub))
            foundlinks.push_back(href->value);
    }

    GumboVector* children = &node->v.element.children;
    for (unsigned int i = 0; i < children->length; ++i) {
        search_for_links(static_cast<GumboNode*>(children->data[i]));
    }
}


void Parser::parse_html(std::string contents, std::string baseurl) {
    GumboOutput* output = gumbo_parse(contents.c_str());
    // get all text on html page
    std::string plaintext = cleantext(output->root);

    // search html text for email addresses
    std::vector<std::string> found_emails = textsearch.find_emails(plaintext);

    // search html document tree for href links then destroy document tree
    search_for_links(output->root);
    gumbo_destroy_output(&kGumboDefaultOptions, output);

    // filter found href links
    for (auto url : foundlinks) {
        if (urlfilter->is_valid(url)) {
            urlfrontier->add_url(url);
        }
    }
}