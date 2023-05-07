#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
ifstream fin("abce.in");
ofstream fout("abce.out");
#include "header_files/RBT.h"

//add DONE
//remove TODO : (done remove part) check conditions!(partially solved)
//find DONE
//succ DONE
//pred DONE
//cout_sort(start,end) DONE
int main(){
    
    RedBlackTree tree;
    int nr_exercitii;
    fin>>nr_exercitii;
    int type;
    int nr;
    for(int i = 0; i < nr_exercitii; i ++)
    {
        fin>>type>>nr;

        switch(type)
        {
            case 1: {tree.add(nr);break;}
            case 2: {tree.remove(nr);break;}
            case 3: {fout<<tree.find(nr)<<endl;break;}
            case 4: {if(tree.find(nr)){fout<<tree.pred(nr)<<endl;}else{fout<<0<<endl;}break;}
            case 5: { if(tree.find(nr)){fout<<tree.succ(nr)<<endl;}else{fout<<0<<endl;}break;}
            case 6: {int nr2; fin>>nr2; tree.inOrder(nr,nr2);break;}
        }
        //case 6 , we add another int nr2;
    }
    // tree.add(3);
    // tree.add(1);
    // tree.add(5);
    // tree.add(7);
    // tree.add(6);
    // tree.add(8);
    // tree.add(9);
    // tree.add(10);



    // cout << tree.find(10);

    //tree.remove(3);
    // cout << tree.succ(3)<<endl;
    // cout << tree.pred(1)<<endl;
    // tree.inOrder(5,7);
    // tree.print();
    return 0;
}