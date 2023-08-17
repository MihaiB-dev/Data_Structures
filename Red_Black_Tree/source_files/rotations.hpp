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
