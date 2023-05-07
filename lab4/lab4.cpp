#include <iostream>
#include <vector>
using namespace std;

class Heap {
    //Heap.size()
    vector<int> v_;

    void moveup(int nod_pos);
    void movedown(int nod_pos);
    public:

        void pop();
        int top();
        void push(int val);

        void afisare();
};
void Heap::afisare(){
    for(auto p = 0; p < v_.size(); p++) cout << v_[p]<< " ";
}
void Heap::pop() {
    swap(v_[0], v_[v_.size()-1]);
    v_.pop_back();
    movedown(0);
};

void Heap::movedown(int nod_pos)
{
    // daca este frunza
    // daca are 2 fii
    // daca are 1 fiu
    int left = 2*nod_pos+1;
    int right = 2*nod_pos+2;
    if(left == v_.size() && v_[nod_pos] > v_[left]) swap(v_[nod_pos], v_[left]);

    if(right == v_.size() && v_[nod_pos] > v_[right]) swap(v_[nod_pos], v_[right]);

    if(left<=v_.size() && right <= v_.size())
        if(v_[left] < v_[right] && v_[nod_pos] > v_[left])
            {swap(v_[nod_pos], v_[left]); movedown(left);}

        else if (v_[left] < v_[right] && v_[nod_pos] > v_[right])
            {swap(v_[nod_pos], v_[right]); movedown(right);}
}
int Heap::top() {
    return 1;
};

void Heap::push(int val) {
    v_.push_back(val); //adaugam valoarea pe ultima pozitie
    moveup(v_.size()-1);
}

void Heap::moveup(int nod_pos)
{   while (nod_pos > 0)
    {
        if (v_[nod_pos] < v_[(nod_pos-1) / 2]) 
        {
            swap(v_[nod_pos],v_[(nod_pos-1) / 2]);
            nod_pos = (nod_pos - 1)/2;
        }
        else break;
    }
   
}

int main(){

    Heap heap;

    heap.push(1);
    heap.push(4);
    heap.push(9);
    heap.push(6);
    heap.push(8);
    heap.push(12);
    heap.push(16);

    heap.pop();

    heap.afisare();
    return 0;
}