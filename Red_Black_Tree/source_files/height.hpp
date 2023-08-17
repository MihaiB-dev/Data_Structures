int RedBlackTree::height(Node* node){
    if(node == NULL)return 0;
    int leftheight = height(node->left) + 1;
    int rightheight = height(node->right) + 1;

    if(leftheight > rightheight)return leftheight;
    return rightheight;
}
int RedBlackTree::height(){
    if(root == NULL)return 0;
    return height(root) - 1;
}