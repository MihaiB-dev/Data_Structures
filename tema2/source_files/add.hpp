void RedBlackTree::add_deep( Node* parent, Node* newNode){
    //verify if our node is bigger or lower than the node where we are at.
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

void RedBlackTree::add (int fc_value)
{
    Node* node = new Node(fc_value); // create a new node with the value of fc_value
    if(root == NULL){root = node; root->black = true; size ++; return;}
    add_deep(root, node);
};