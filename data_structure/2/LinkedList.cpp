//
// Created by badcw on 18-11-19.
//

#include <cstdio>
#include <algorithm>
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
    if (len == 0) {
        root = nullptr;
        return;
    }
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

LinkedList addTwoLink(const LinkedList &a, const LinkedList &b) {
    Node *t1 = a.root;
    Node *t2 = b.root;
    if (t1 == nullptr)
        return b;
    else if (t2 == nullptr)
        return a;
    int tmp[] = {t1->getVal() + t2->getVal()};
    LinkedList res(tmp, 1);
    Node *p = res.root;
    while (t1->getNxt() != nullptr && t2->getNxt() != nullptr) {
        t1 = t1->getNxt();
        t2 = t2->getNxt();
        res.Insert(p, t1->getVal() + t2->getVal());
        p = p->getNxt();
    }
    if (t2->getNxt() == nullptr) {
        std::swap(t1, t2);
    }
    t2 = t2->getNxt();
    while (t2 != nullptr) {
        res.Insert(p, t2->getVal());
        p = p->getNxt();
        t2 = t2->getNxt();
    }
    return res;
}
