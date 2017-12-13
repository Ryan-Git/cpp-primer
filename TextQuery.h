//
// Created by Ryan on 08/12/2017.
//

#ifndef CPP_PRIMER_TEXTQUERY_H
#define CPP_PRIMER_TEXTQUERY_H

#include <memory>
#include <utility>
#include <vector>
#include <set>
#include <map>

class QueryResult;

class TextQuery {

public:
    using line_no = std::vector<std::string>::size_type;

    explicit TextQuery(std::ifstream &ifstream);

    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file;

    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

class QueryResult {
    friend std::ostream &print(std::ostream &, const QueryResult &);

public:
    using line_no = std::vector<std::string>::size_type;

    QueryResult(std::string s, std::shared_ptr<std::set<line_no>> p, std::shared_ptr<std::vector<std::string>> f)
            : sought(s), lines(std::move(p)), file(std::move(f)) {}

    std::set<line_no>::iterator begin(){
        return lines->begin();
    }

    std::set<line_no>::iterator end(){
        return lines->end();
    }

    std::shared_ptr<std::vector<std::string>> get_file(){
        return file;
    }

private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};

#endif //CPP_PRIMER_TEXTQUERY_H
