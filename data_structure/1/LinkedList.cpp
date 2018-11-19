//
// Created by badcw on 18-11-19.
//

#include <cstdio>
#include "LinkedList.h"

bool LinkedList::Insert(Node *now, int _val) {
    Node *newNode = new Node(_val);
    if (newNode == nullptr) return false;
    newNode->getNxt() = now->getNxt();
    now->getNxt() = newNode;
    return true;
}

bool LinkedList::combine(const LinkedList &oth) {
    Node* p = oth.root;
    Node* pnow = root;
    bool flag = true;
    while (p != nullptr) {
        while (pnow->getNxt() != nullptr && pnow->getNxt()->getVal() < p->getVal()) {
            pnow = pnow->getNxt();
        }
        if (pnow->getNxt() == nullptr || pnow->getNxt()->getVal() != p->getVal())
            flag = Insert(pnow, p->getVal());
        if (!flag) break;
        p = p->getNxt();
    }
    return flag;
}

LinkedList::LinkedList(int *a, int len) {
    root = new Node(a[0]);
    Node *t = root;
    for (int i = 1; i < len; ++i) {
        Insert(t, a[i]);
        t = t->getNxt();
    }
}

void LinkedList::print() {
    Node *t = root;
    if (t == nullptr) {
        printf("no data!\n");
        return;
    }
    printf("%d", t->getVal());
    t = t->getNxt();
    while (t != nullptr) {
        printf("->%d", t->getVal());
        t = t->getNxt();
    }
    printf("\n");
}
