#include <bits/stdc++.h>
using namespace std;


typedef struct bnode {
    int data;
    struct bnode *lchild, *rchild;
} BNode, *bitree;


/*如果返回成功，p指向查找成功的那个节点，如果失败就返回查找路径上的最后一个节点*/
int SearchBST(bitree T, int key, bitree f, bitree &p)/*T为根节点，key为要查找的值，f为T的双亲，f的初值为NULL*/
{
    if (!T) {
        p = f;
        return 0;
    } else {
        if (T->data == key) {
            p = T;
            return 1;
        } else if (T->data < key)
            return SearchBST(T->rchild, key, T, p);
        else
            return SearchBST(T->lchild, key, T, p);
    }
}

/*插入节点*/
int InsertBST(bitree &T, int key)
{
    bitree p, s;
    if (!SearchBST(T, key, NULL, p))
    {
        s = new BNode[sizeof(BNode)];
        s->data = key;//初始化
        s->lchild = s->rchild = NULL;
        if (!p)
            T = s;
        else if (key < p->data)
            p->lchild = s;
        else
            p->rchild = s;
        return 1;
    }
    return 0;
}

/*删除节点p*/
int Del(bitree &p) {
    bitree q;
    if (!p->lchild && !p->rchild)//没有子女
    {
        q = p;
        p = NULL;
        delete q;
        return 1;
    }
    if (!p->lchild && p->rchild)//只有右儿子
    {
        q = p;
        p = p->rchild;
        delete q;
        return 1;
    }
    if (p->lchild && !p->rchild)//只有左儿子
    {
        q = p;
        p = p->lchild;
        delete q;
        return 1;
    }
    if (p->lchild != NULL && p->rchild != NULL)//左右儿子都存在
    {
        q = p->lchild;
        while (q->lchild)
            q = q->lchild;
        q->rchild = p->rchild;
        q = p;
        p = p->lchild;
        delete q;
        return 1;
    }
    return 0;
}


/*删除指定节点*/
int DeleteBST(bitree &T, int key)
{
    if (!T)
        return 0;
    else {
        if (T->data == key)
            return Del(T);
        else if (T->data > key)
            return DeleteBST(T->lchild, key);
        else
            return DeleteBST(T->rchild, key);
    }
}


void inorder(bitree bt)//中序遍历
{
    bitree p = bt;
    stack<bitree> s;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->lchild;
        }
        if (!s.empty()) {
            printf("%d ", s.top()->data);
            p = s.top()->rchild;
            s.pop();
        }
    }
    printf("\n");
}


int main() {
    int n, x, i;
    bitree T;
    while (scanf("%d", &n) != EOF) {
        T = NULL;
        for (i = 0; i < n; i++) {
            scanf("%d", &x);
            InsertBST(T, x);
        }
        inorder(T);
        printf("chose a number to delete:\n");
        scanf("%d", &x);
        DeleteBST(T, x);
        inorder(T);
    }
}