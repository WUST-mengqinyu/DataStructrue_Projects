#include <cstdio>
#include "LinkedList.h"

int main(int argc,char *argv[])
{
    int a[] = {1, 2, 5, 7, 10};
    int b[] = {2, 3, 7, 9, 11};
    LinkedList linka(a, 5);
    LinkedList linkb(b, 5);

    linka.print();
    linkb.print();

    linka.combine(linkb);

    linka.print();
    return 0;
}