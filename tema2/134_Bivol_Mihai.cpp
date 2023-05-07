#include <iostream>
#include <queue>
#include <fstream>

using namespace std;
ifstream fin("abce.in");
ofstream fout("abce.out");

class Node {
    public:
    long value;
    Node *left,*right,*parent;
    bool isLeftChild, black; 

    Node(long fc_value): value(fc_value), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false){};
    Node(): value(10000000000), left(NULL), right(NULL), parent(NULL), black(false), isLeftChild(false){};
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

    void prlong_node();
};
class RedBlackTree {

    Node *root;
    long size;

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
    long blackNodes(Node* node); 
    void checkColor(Node* node); 
    //-------------------------------------

    void add_deep( Node* parent, Node* newNode); 
    Node* remove_private(Node* node);
    Node* find_private(Node* node, long val);
    long height(Node* node);
    Node* succesor(Node* node);
    Node* predecessor(Node* node);
    void inOrder(Node* node,long min, long max);
    void check_after_remove(bool removed_black,Node* node, long last_left, long last_right);
public:
    void add (long fc_value);
    void remove(long value);
    bool find(long val);
    long height();
    long succ(long val);
    long pred(long val);
    void inOrder(long min, long max);
    
    //optional:
    bool empty();
    void prlong();
};

void RedBlackTree::leftRotate(Node* node){// node is the grandparent
    Node* temp = new Node;
    *temp = *(node->right);// temp = B

    delete node->right;

    node->right = temp->left;  // A -> right = what B has on the left

    if(node->right != NULL){ // update the right child if it's not NULL
        node->right->parent = node;
        node->right->isLeftChild = false;
    }
    //verify if node has a parent
    if(node->parent == NULL){
        //we are root node!!
        root = temp;
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

void RedBlackTree::rightRotate(Node* node){// node is the grandparent
    Node* temp = new Node;
    *temp = *(node->left);// temp = B

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
        root = temp;
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

Node* RedBlackTree::leftRightRotate(Node* node){// node is the grandparent
    leftRotate(node->left);
    rightRotate(node);
    return node->parent;
};

Node* RedBlackTree::rightLeftRotate(Node* node){
    rightRotate(node->right);
    leftRotate(node);
    return node->parent;
};

void RedBlackTree::rotate(Node* node){
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

void RedBlackTree::corectTree(Node* node){ //verify the aunt (black or red) black_aunt - rotate, red_aunt - color flip
    if(node->parent->isLeftChild){ // we are on the left side
        //aunt is node->parent->parent->right
        if(node->parent->parent->right == NULL || node->parent->parent->right->black)return rotate(node); // the aunt is black
            
        if(node->parent->parent->right != NULL)node->parent->parent->right->black = true;    

        node->parent->parent->black = false;
        node->parent->black = true;

        if(root->black == false){root->black = true;}   
        return;
        
            }
    else //we are on the right side and see for the grandparents left child
    {
        if(node->parent->parent->left == NULL || node->parent->parent->left->black){return rotate(node);} // the aunt is black
            
        if(node->parent->parent->left != NULL){node->parent->parent->left->black = true;}    

        node->parent->parent->black = false;
        node->parent->black = true;

        if(root->black == false){root->black = true;}   
        return;
    }
        
}
//NOT USED
long RedBlackTree::blackNodes(Node* node){
    if(node == NULL){
        return 1;
    }
    long rightBlackNodes = blackNodes(node->right);
    long leftBlackNodes = blackNodes(node->left);
    if(rightBlackNodes != leftBlackNodes){
        corectTree(node);
    }
    if(node->black)leftBlackNodes++;
    return leftBlackNodes;
}

void RedBlackTree::checkColor(Node* node){
    if(node == root){return;} // we will get up on the tree till we are at the root node.
    if(!node->black && !node->parent->black) //if 2 consecutive reds
        {corectTree(node);}

    //long black = blackNodes(node); // verify if there are the same number of black nodes on each side.


    if(node->parent){checkColor(node->parent);}; //recursive function which goes up to the parent.}
};

void RedBlackTree::add_deep( Node* parent, Node* newNode){
    //verify if our node is bigger or slower than  the node where we are at.
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

void RedBlackTree::add (long fc_value)
{
    Node* node = new Node(fc_value); // create a new node with the value of fc_value
    if(root == NULL){root = node; root->black = true; size ++; return;}
    add_deep(root, node);
};

void Node::prlong_node() { 
					
    cout << endl;
    cout << "Node: " << value << endl;
    if (parent != NULL) { 
        cout << "Parent: " << parent->value << endl;
    } else { cout << "Parent: NULL" << endl; }
    if (left != NULL) {
        cout << "Left: " << left->value << endl;
    } else { cout << "Left: NULL" << endl; }
    if (right != NULL) {
        cout << "Right: " << right->value << endl;
    } else { cout << "Right: NULL" << endl; }
    if(black == true) {cout<< "Color: black"<< endl;}
    else {cout <<"Color:red"<<endl;}

}

void RedBlackTree::prlong() {
	queue<Node*> to_visit;
	if (empty()) {
		throw invalid_argument("Nothing to prlong, tree empty.");
	} else {
		to_visit.push(root);
		Node* current = root;
		cout << "----prlong----";
		while ( !to_visit.empty()) {
			current->prlong_node();
			if (current->left != NULL) {
				to_visit.push(current->left);
			}
			if (current->right != NULL) {
				to_visit.push(current->right);
			}
			to_visit.pop();
			current = to_visit.front();
		}
	}
}

bool RedBlackTree::empty() {
	if (root == NULL) {
		return true;
	} else { 
		return false; 
	}
}

long RedBlackTree::height(Node* node){
    if(node == NULL)return 0;
    long leftheight = height(node->left) + 1;
    long rightheight = height(node->right) + 1;

    if(leftheight > rightheight)return leftheight;
    return rightheight;
}
long RedBlackTree::height(){
    if(root == NULL)return 0;
    return height(root) - 1;
}

Node* RedBlackTree::find_private(Node* node, long val) {
	if(node == NULL)return NULL;

	if(val == node->value){
		return node;
	}
	else if(val <= node->value )
	{
		return find_private(node->left, val);
		;
	}else{
		return find_private(node->right,val);
	}
}

bool RedBlackTree::find(long val) {

	Node* found = find_private(root, val);
	if(found){return true;}else {return false;}
	
}

Node* RedBlackTree::remove_private(Node* node) {
    //find the succesor
	if(node->right){//we are certain that we have a succesor.
		Node* succesor = node->right;
		while(succesor){
			if(succesor->left){
				succesor = succesor->left;
			}else{break;}
		}
        //change the the node.
        node->value = succesor->value;
        node->black = succesor->black;

        //delete the succesor.
        if(succesor->left) // daca mai are noduri in stanga
        {   
            succesor->left->parent = succesor->parent;
            succesor->parent->right = succesor->left;
            Node* copy = succesor->left;
            succesor = NULL;
            size --;
            return copy->parent;
        }else{
            if(succesor->right){ // daca mai are noduri in dreapta
                succesor->parent->right = succesor->right;
                succesor->right->parent = succesor->parent;
                Node* copy = succesor->right;
                succesor = NULL;
                size --;
                return copy->parent;
            }else{ // daca este leaf
                if(succesor->isLeftChild){succesor->parent->left = NULL;}else{succesor->parent->right = NULL;}
                
                succesor = NULL;
                size--;
                return node;
            }
            
        }
        
    }
    if(node->left){//connect the left part to the parent of the node and disconnect the node.
        node->left->parent = node->parent;
        node->parent->right = node->left;
        Node* copy = node->left;
        node = NULL;
        size --;
        return copy->parent;
    }else{//it's a leaf , we can disconnect it directly, minus for size.
        if(node->isLeftChild){node->parent->left = NULL;} else {node->parent->right = NULL;}; 
        Node* parent = node->parent;
        node = NULL;
        size--;
        return parent; 
    }
    

};
void RedBlackTree::check_after_remove(bool removed_black,Node* node, long last_left, long last_right){
    if(removed_black != node->black){ //case 1 if one is red and other is black
        node->black = true; return;
    }
    else
    {
        //if(node->left)if(node->left->value != last_left){node->black = false; node->right->black = true; leftRotate(node);}
        //if(node->left)if(node->right->value != last_right){node->black = false; node->right->black = true; rightRotate(node);}
    }

}
void RedBlackTree::remove(long value){
    Node* node = find_private(root,value);
    bool removed_black = node->black;
    long last_value_left;
    long last_value_right;
    if(node->left){ last_value_left = node->left->value;}
    if(node->right){ last_value_right = node->right->value;}
    
    Node* new_value = remove_private(node);//returns one up ( parent of deletion )
    if(new_value->value != 10000000000){
        //check_after_remove(removed_black,new_value, last_value_left, last_value_right); 
    }else{delete new_value;}
    
}

Node* RedBlackTree::succesor(Node* node) {
	if(node->right){//cazul in care mergem in jos
		Node* temp = node->right;
		while(temp){
			if(temp->left){
				temp = temp->left;
			}else{return temp;}
		}
	}else{
		if(node == root){return node;}
		Node* temp = node->parent;

		do{
			if(temp->value > node->value){return temp;}
			else {temp = temp->parent;}
			
		}while(!temp->parent);	
	}
    if(node == root){return root;} // if it's a route only!
}

long RedBlackTree::succ(long val) {
	
	Node* node = find_private(root,val);
	
	Node* succ = succesor(node);

	return succ->value;
};

Node* minim(Node* node) {
if(node->left == NULL) { return node; }

return minim(node->left);	
};

Node* RedBlackTree::predecessor(Node* node) {


	if(node->left){//cazul in care mergem in jos
		Node* temp = node->left;
		while(temp){
			if(temp->right){
				temp = temp->right;
			}else{return temp;}
		}
	}else{
		if(node->value == minim(node)->value){cout<<"This is the minim number in the tree, it has no predecessor";return new Node();}
		if(node == root){return node;}
		Node* temp = node->parent;

		do{
			if(temp->value < node->value){return temp;}
			else {temp = temp->parent;}
			
		}while(!temp->parent);	
	}
    if(node == root){return root;} // if it's a route only!
}

long RedBlackTree::pred(long val) {
	
	Node* node = find_private(root,val);
	Node* pred = predecessor(node);
	if(pred->value != 10000000000){return pred->value;}
	return 0;
	
};

  void RedBlackTree::inOrder(long min, long max) {
    inOrder(root,min,max);
  }
long ok = 0;
void RedBlackTree::inOrder(Node* node, long min, long max) {

    if (node == NULL) {
      return;
    }
    inOrder(node->left, min,max);
    if(node->value >= min && node->value <= max){ok = 1;fout << node->value << " ";}
    inOrder(node->right, min, max);
    if(ok == 1){fout<<endl;}
    ok = 0;
  }



//add DONE
//remove TODO : (done remove part) check conditions!(partially solved)
//find DONE
//succ DONE
//pred DONE
//cout_sort(start,end) DONE
int main(){
    
    RedBlackTree tree;
    long nr_exercitii;
    fin>>nr_exercitii;
    long type;
    long nr;
    for(long i = 0; i < nr_exercitii; i ++)
    {
        fin>>type>>nr;

        switch(type)
        {
            case 1: {tree.add(nr);break;}
            case 2: {if(tree.find(nr))tree.remove(nr);break;}
            case 3: {fout<<tree.find(nr)<<endl;break;}
            case 4: {if(tree.find(nr)){fout<<tree.pred(nr)<<endl;}else{fout<<0<<endl;}break;}
            case 5: { if(tree.find(nr)){fout<<tree.succ(nr)<<endl;}else{fout<<0<<endl;}break;}
            case 6: {long nr2; fin>>nr2; tree.inOrder(nr,nr2);break;}
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