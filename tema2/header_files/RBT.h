class Node {
    public:
    int value;
    Node *left,*right,*parent;
    bool isLeftChild, black, doubleBlack; 

    Node(int fc_value): value(fc_value), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false), doubleBlack(false){};
    Node(): value(0), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false), doubleBlack(false){};
    Node& operator=(Node& node)
    {
        value = node.value;
        left = node.left;
        right = node.right;
        parent = node.parent;
        black = node.black;
        isLeftChild = node.isLeftChild;
        doubleBlack = node.doubleBlack;
        return *this;
    };

    void print_node();
};
class RedBlackTree {

    Node *root;
    int size;

public:
    RedBlackTree(){
        root = NULL;
        size = 0;
    }
private:

    
    //rotations:
    void leftRotate(Node* node);
    void rightRotate(Node* node);
    Node* leftRightRotate(Node* node); 
    Node* rightLeftRotate(Node* node);
    void rotate(Node* node); 
    //-----------------

    //checking:
    void corectTree(Node* node); 
    int blackNodes(Node* node); 
    void checkColor(Node* node); 
    //-------------------------------------

    void add_deep( Node* parent, Node* newNode); 
    void remove_private(Node* node);
    Node* find_private(Node* node, int val);
    int height(Node* node);
    Node* succesor(Node* node);
    Node* predecessor(Node* node);
    void inOrder(Node* node,int min, int max);
    void check_before_remove(Node* node);
    void handleDoubleBlack(Node* node,bool isLeftChild);
public:
    void add (int fc_value);
    void remove(int value);
    bool find(int val);
    int height();
    int succ(int val);
    int pred(int val);
    void inOrder(int min, int max);
    
    //optional:
    bool empty();
    void print();
};

#include "../source_files/rotations.hpp"
#include "../source_files/checking.hpp"
#include "../source_files/add.hpp"
#include "../source_files/print.hpp"
#include "../source_files/height.hpp"
#include "../source_files/find.hpp"
#include "../source_files/remove.hpp"
#include "../source_files/succ_pred.hpp"
#include "../source_files/inOrder.hpp"