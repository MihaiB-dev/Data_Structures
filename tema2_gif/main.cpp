#include <iostream>
#include <queue>
using namespace std;
#include "header_files/RBT.h"

//add DONE
//remove TODO
//find DONE
//succ TODO
//pred TODO
//cout_sort(start,end);
int main(){
    RedBlackTree tree;

    tree.add(3);
    tree.add(1);
    tree.add(5);
    tree.add(7);
    tree.add(6);
    tree.add(8);
    tree.add(9);
    tree.add(10);

    tree.print();

    cout << tree.find(10);
    return 0;
}