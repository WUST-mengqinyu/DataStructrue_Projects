//
// Created by badcw on 18-11-19.
//

#ifndef INC_1_NODE_H
#define INC_1_NODE_H

class Node {
    int data;
    Node *nxt;
public:
    explicit Node(int _val = 0);
    Node* & getNxt();
    int getVal();
};


#endif //INC_1_NODE_H
