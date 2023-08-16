#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#define P 666013
struct Node {
    long value;
    Node* next;

    public:
    Node():value(-1), next(NULL){}
};

class Hash {

    Node *hash_vector[P];
    
    public:
    Hash(){for(int i = 0; i < P; i++)hash_vector[i] =new Node();}
    void add(long value);
    void remove(long value);
    bool find(long value);
    
};

void Hash::add(long value){
int division = value%P;
// try to add into hash
Node* node = hash_vector[division];
    if(node->value == -1)
    {
        node->value = value;
        return;
    }

    for(auto n = node; n != NULL; n = n->next)
    {
        if(n->next == NULL) //we found the last node to place our value
        {
            Node* new_node = new Node();
            new_node->value = value;
            n->next = new_node;
            break;
        }
    }         
}

void Hash::remove(long value){
    int division = value%P;
    Node * node = hash_vector[division];
    if(node->value == value)
    {
        if(node->next != NULL){hash_vector[division] = node->next;}
        else
        {
            node->value = -1;
        }
    }else
    {
        for(auto n1 = node, n2 = node->next; n2 != NULL; n1 = n1->next, n2 = n2->next)
        {
            if(n2->value == value)
            {
                if(n2->next != NULL){n1->next = n2->next;}//if it has something more on the right side
                else{
                    n1->next = NULL; // if it's the last number
                    delete n2;
                }
                break;
            }
        }
    }
}

bool Hash::find(long value){
    int division = value%P;
    
    for(auto n = hash_vector[division]; n != NULL; n= n->next)
    {
        if(n->value == value)
        return true;
    }
    return false;
}

int main()
{
    ifstream fin("hashuri.in");
    ofstream fout("hashuri.out");
    Hash hash;
    int nr, val, x;
    fin>>nr;
    for(int i = 0; i < nr; i++){
        fin>>val>>x;
        switch(val)
        {
            case 1 : {hash.add(x);break;}
            case 2 : {hash.remove(x);break;}
            case 3 : {fout<<hash.find(x)<<endl;break;}
        }
    }
    fin.close();
    fout.close();
}