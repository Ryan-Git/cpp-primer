//
// Created by Ryan on 08/12/2017.
//

#include <set>
#include <vector>
#include "Folder.h"

int main() {
}

void Folder::addMsg(Message *m) {
    msgs.insert(m);
}

void Folder::remMsg(Message *m) {
    msgs.erase(m);
}
