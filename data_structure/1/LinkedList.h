//
// Created by badcw on 18-11-19.
//

#ifndef INC_1_LINK_H
#define INC_1_LINK_H


#include "Node.h"

class LinkedList {
    Node* root;
    bool Insert(Node *now, int _val);
public:
    bool combine(const LinkedList &oth);
    LinkedList(int a[], int len);
    void print();
};


#endif //INC_1_LINK_H
