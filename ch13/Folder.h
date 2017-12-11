//
// Created by Ryan on 08/12/2017.
//

#ifndef CPP_PRIMER_FOLDER_H
#define CPP_PRIMER_FOLDER_H

class Message;
class Folder {
    
    std::set<Message*> msgs;
    
public:
    void addMsg(Message *);
    void remMsg(Message *);
};


#endif //CPP_PRIMER_FOLDER_H
