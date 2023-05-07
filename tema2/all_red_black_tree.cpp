#include <iostream>
using namespace std;


class Node {
    public:
    int value;
    Node *left,*right,*parent;
    bool isLeftChild, black; 

    Node(int fc_value): value(fc_value), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false){};
    Node(){
        value = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
        black = false;
        isLeftChild = false;
    };
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
};

class RedBlackTree {
    public:
    Node *root;
    int size;

    RedBlackTree(){
        root = NULL;
        size = 0;
    }
};

RedBlackTree RBT;


int height(Node* node){
    if(node == NULL)return 0;
    int leftheight = height(node->left) + 1;
    int rightheight = height(node->right) + 1;

    if(leftheight > rightheight)return leftheight;
    return rightheight;
}
int height(){
    if(RBT.root == NULL)return 0;
    return height(RBT.root) - 1;
}

// A
// "\"
//   B
// "/""\"
//Smth  C
void leftRotate(Node* node){// node is the grandparent
    Node* temp = new Node;
    *temp = *(node->right);// temp = B
    cout<<"Left Rotate engage:";
    cout<< node->value<<endl;

    delete node->right;

    node->right = temp->left;  // A -> right = what B has on the left

    if(node->right != NULL){ // update the right child if it's not NULL
        node->right->parent = node;
        node->right->isLeftChild = false;
    }
    //verify if node has a parent
    if(node->parent == NULL){
        //we are root node!!
        RBT.root = temp;
        temp->parent = NULL;
    }
    else 
    {
        temp->parent = node->parent; //connect our B parent to the red black tree
        if(node->isLeftChild){
            temp->isLeftChild = true; // put it in the correct place (leftside)
            temp->parent->left = temp;
        } else {
            temp->isLeftChild = false;// put it in the correct place (rightside)
            temp->parent->right = temp;
        }

    }

    temp->left = node;
    node->isLeftChild = true;
    node->parent = temp;
    if(node->parent->right){node->parent->right->parent = node->parent;}
}

void rightRotate(Node* node){// node is the grandparent
    Node* temp = new Node;
    *temp = *(node->left);// temp = B
    cout<<"Right Rotate engage:";
    cout<< node->value<<endl;

    delete node->left;
    // Node temp = *(node->left); 
    node->left = temp->right;  // A -> left = what B has on the right

    if(node->left != NULL){ // update the left child if it's not NULL
        node->left->parent = node;
        node->left->isLeftChild = true;
    }
    //verify if node has a parent
    if(node->parent == NULL){
        //we are root node!!
        RBT.root = temp;
        temp->parent = NULL;
    }
    else 
    {
        temp->parent = node->parent; //connect our B parent to the red black tree
        if(node->isLeftChild){
            temp->isLeftChild = true; // put it in the correct place (leftside)
            temp->parent->left = temp;
        } else {
            temp->isLeftChild = false;// put it in the correct place (leftside)
            temp->parent->right = temp;
        }

    }

    temp->right = node;
    node->isLeftChild = false;
    node->parent = temp;
    if(node->parent->left){node->parent->left->parent = node->parent;}
}

//     A           A
//    /           /
//   B    ->     C     ->    C
//   '\'        /          / '\'
//     C       B          B    A
Node* leftRightRotate(Node* node){// node is the grandparent
    leftRotate(node->left);
    rightRotate(node);
    return node->parent;
};

Node* rightLeftRotate(Node* node){
    rightRotate(node->right);
    leftRotate(node);
    return node->parent;
};


void rotate(Node* node){
    if(node->isLeftChild)
    {
        //left child + left subtree -> right rotation
        if(node->parent->isLeftChild)
        {   
            rightRotate(node->parent->parent);
            //after rotation we need to correct the colors (change to black parent and 2 red siblings)
            node->black = false;
            node->parent->black= true;
            if(node->parent->right!=NULL)node->parent->right->black = false;

            return;
        }
        //left child + right subtree -> right left rotation
        node = rightLeftRotate(node->parent->parent);
        //the node we are starting with becomes the parent due to rightLeft rotation
        //correct colors
        cout<<"node value after right left rotation: "<<node->value<<endl;

        node->black = true;
        node->right->black = false;
        node->left->black = false;
        return;
    }
    //Here we know we are on the right child

    //right child + right subtree -> left rotation
    if(node->parent->isLeftChild == false)
        {
            leftRotate(node->parent->parent);
            //after rotation we need to correct the colors (change to black parent and 2 red siblings)
            node->black = false;
            node->parent->black= true;
            if(node->parent->left!=NULL)node->parent->left->black = false;

            return;
        }
    
    //right child + left subtree -> left right rotation
    node = leftRightRotate(node->parent->parent);
    //the node we are starting with becomes the parent due to left right rotation
    //correct colors
    node->black = true;
    node->right->black = false;
    node->left->black = false;
    return;
}

void corectTree(Node* node){ //verify the aunt (black or red) black_aunt - rotate, red_aunt - color flip
    cout<<"corectTree"<<endl;
    if(node->parent->isLeftChild){ // we are on the left side
        //aunt is node->parent->parent->right
        if(node->parent->parent->right == NULL || node->parent->parent->right->black)return rotate(node); // the aunt is black
            
        if(node->parent->parent->right != NULL)node->parent->parent->right->black = true;    

        node->parent->parent->black = false;
        node->parent->black = true;

        if(RBT.root->black == false){RBT.root->black = true;}   
        return;
        
            }
    else //we are on the right side and see for the grandparents left child
    {
        if(node->parent->parent->left == NULL || node->parent->parent->left->black){return rotate(node);} // the aunt is black
            
        if(node->parent->parent->left != NULL){node->parent->parent->left->black = true;}    

        node->parent->parent->black = false;
        node->parent->black = true;

        if(RBT.root->black == false){RBT.root->black = true;}   
        return;
    }
        
}

int blackNodes(Node* node){
    if(node == NULL){
        return 1;
    }
    int rightBlackNodes = blackNodes(node->right);
    int leftBlackNodes = blackNodes(node->left);
    if(rightBlackNodes != leftBlackNodes){
        corectTree(node);
    }
    if(node->black)leftBlackNodes++;
    return leftBlackNodes;
}

void checkColor(Node* node){
    if(node == RBT.root){return;} // we will get up on the tree till we are at the root node.
    if(!node->black && !node->parent->black) //if 2 consecutive reds
        {corectTree(node); int black = blackNodes(node);}
    if(node->parent){checkColor(node->parent);}; //recursive function which goes up to the parent.}
};
void add_deep( Node* parent, Node* newNode){
    //verify if our node is bigger or slower than a the node where are at.
    if(newNode->value >= parent->value){//add to the right.
        if(parent->right == NULL) // create the right side if it doesn't exist
        {
            parent->right = newNode;
            newNode->parent = parent;
            newNode->isLeftChild = false; // optional because we design it to have false, but is good to be here.
            return;
        }
        add_deep(parent->right, newNode); // make a recursive function so that it goes to the right side if it exists.
    }
    //do the same thing for the left side
    else{
        if(parent->left == NULL) // create the left side if it doesn't exist
        {
            parent->left = newNode;
            newNode->parent = parent;
            newNode->isLeftChild = true; // optional because we design it to have false, but is good to be here.
            return;
        }
        add_deep(parent->left, newNode); // make a recursive function so that it goes to the right side if it exists.
    }
    checkColor(newNode); //verify if the rules are not violated : no 2 reds consecutive, the same number of blacks, black root.
};

void add (int fc_value)
{
    Node* node = new Node(fc_value); // create a new node with the value of fc_value
    if(RBT.root == NULL){RBT.root = node; RBT.root->black = true; RBT.size ++; return;}
    add_deep(RBT.root, node);
};

int main(){
add(3);
add(1);
add(5);
add(7);
add(6);
add(8);
add(9);
add(10);

cout<<"Height: "<<height()<<endl;
cout<<"All:"<<endl;
cout<<RBT.root->value<<endl;

cout<<RBT.root->left->value<<endl;
cout<<RBT.root->right->value<<" "<<RBT.root->right->black<<endl;
cout<<RBT.root->right->left->value<<" "<<RBT.root->right->left->black<<endl;
cout<<RBT.root->right->right->value<<" "<<RBT.root->right->right->black<<endl;
}