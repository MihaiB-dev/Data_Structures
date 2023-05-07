#include <iostream>
using namespace std;

class Node{
public:
    Node* next;
    int value;
    Node* prev;

    Node(int element){
        next = nullptr;
        value = element;
        prev = nullptr;
    };
};

class List{
    //TODO push_back, pop_back

    Node* begin;
    Node* end;
public:
    List(){
        begin = nullptr;
        end = nullptr;
    }
    
    void pop_back(){
        Node* new_last = end->prev;
        new_last->next = nullptr;
        end = new_last;
    }
    void push_back(int element)
    {
        Node* new_node = new Node(element);
        if (!begin)
        {
            begin = new_node;
            end = new_node;
        }
        else
        {
            new_node->prev = end;
            end->next = new_node;
            end = new_node;

        }
    }



    int& get_end(){
        return end->value;

    }

    void print(){
        for(Node* i= begin ; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        cout << endl;
    }
};

int main(){
    List list;
    list.push_back(5);
    list.push_back(5);
    list.push_back(5);
    list.push_back(5);
    list.push_back(5);

    list.pop_back();
// empty	Test whether container is empty (public member function)
// size	    Return size (public member function)
// top	    Access next element (public member function) (DONE)
// push	    Insert element (public member function) (DONE)
// emplace	Construct and insert element (public member function)
// pop	    Remove top element (public member function) (DONE)
// swap
    list.print();
    // cout << list.get_end();
    // list.get_end() = 2;
    // cout << list.get_end();
}