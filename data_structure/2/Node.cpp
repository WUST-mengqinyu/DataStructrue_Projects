//
// Created by badcw on 18-11-19.
//

#include "Node.h"

Node* & Node::getNxt() { return nxt; }

Node::Node(int _val) :data(_val), nxt(nullptr) {}

int Node::getVal() { return data; }
