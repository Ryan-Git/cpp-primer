//
// Created by Ryan on 08/12/2017.
//

#ifndef CPP_PRIMER_MESSAGE_H
#define CPP_PRIMER_MESSAGE_H

#include <string>
#include <set>

class Folder;
class Message {
    friend class Folder;

    std::string contents;
    std::set<Folder*> folders;

    void add_to_folders(const Message &);
    void remove_from_folders();

public:
    explicit Message(const std::string &str=""): contents(str){}

    Message(const Message &);

    Message &operator=(const Message &);

    ~Message();

    void save(Folder &);

    void remove(Folder &);

    void swap(Message &, Message &);
};


#endif //CPP_PRIMER_MESSAGE_H
