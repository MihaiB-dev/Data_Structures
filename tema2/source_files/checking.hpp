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

int RedBlackTree::blackNodes(Node* node){
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

void RedBlackTree::checkColor(Node* node){
    if(node == root){return;} // we will get up on the tree till we are at the root node.
    if(!node->black && !node->parent->black) //if 2 consecutive reds
        {corectTree(node);}
    blackNodes(node); // verify if there are the same number of black nodes on each side.
    if(node->parent){checkColor(node->parent);}; //recursive function which goes up to the parent.}
};