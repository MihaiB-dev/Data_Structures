class Node {
    public:
    int value;
    Node *left,*right,*parent;
    bool isLeftChild, black; 

    Node(int fc_value): value(fc_value), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false){};
    Node(): value(0), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false){};
    Node& operator=(Node& node)
    {
        value = node.value;
        left = node.left;
        right = node.right;
        parent = node.parent;
        black = node.black;
        isLeftChild = node.isLeftChild;
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
    
    Node* find_private(Node* node, int val);
        int height(Node* node);
public:
    void add (int fc_value); // public
    int height();

    //optional:
    bool empty();
    void print(); 

    bool find(int val);
    

};

#include "../source_files/rotations.hpp"
#include "../source_files/checking.hpp"
#include "../source_files/add.hpp"
#include "../source_files/print.hpp"
#include "../source_files/height.hpp"
#include "../source_files/find.hpp"