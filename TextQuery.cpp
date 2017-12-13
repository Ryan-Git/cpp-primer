//
// Created by Ryan on 08/12/2017.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "TextQuery.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::set;
using std::shared_ptr;

void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);

    while (true) {
        cout << "enter word to look for, or q to quite: ";
        string s;
        if (!(cin >> s) || s == "q") {
            break;
        }

        print(cout, tq.query(s)) << endl;
    }
}

TextQuery::TextQuery(std::ifstream &ifstream) : file(new vector<string>) {
    string text;
    while (getline(ifstream, text)) {
        file->push_back(text);
        auto n = file->size() - 1;
        std::istringstream line(text);

        string word;
        while (line >> word) {
            auto &lines = wm[word];
            if (!lines) {
                lines.reset(new set<line_no>);
            }
            lines->insert(n);
        }
    }
}

QueryResult TextQuery::query(const std::string &sought) const {
    static shared_ptr<set<line_no>> nodata(new set<line_no>);

    auto loc = wm.find(sought);
    if (loc == wm.end())
        return QueryResult(sought, nodata, file);
    else
        return QueryResult(sought, loc->second, file);
}

std::ostream &print(std::ostream &os, const QueryResult &qr) {
    os << qr.sought << " occurs " << qr.lines->size() << " " << qr.lines->size()
       << (qr.lines->size() > 1 ? " times" : " time") << endl;

    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
    }
    return os;
}