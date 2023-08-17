#include <iostream>
#include <queue>
#include <climits>
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
    // tree.print();
    return 0;
}