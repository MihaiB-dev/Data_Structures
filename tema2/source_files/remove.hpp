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
void RedBlackTree::check_after_remove(bool removed_black,Node* node, int last_left, int last_right){
    if(removed_black != node->black){ //case 1 if one is red and other is black
        node->black = true; return;
    }
    else
    {
        //if(node->left)if(node->left->value != last_left){node->black = false; node->right->black = true; leftRotate(node);}
        //if(node->left)if(node->right->value != last_right){node->black = false; node->right->black = true; rightRotate(node);}
    }

}
void RedBlackTree::remove(int value){
    Node* node = find_private(root,value);
    bool removed_black = node->black;
    int last_value_left;
    int last_value_right;
    if(node->left){ last_value_left = node->left->value;}
    if(node->right){ last_value_right = node->right->value;}
    
    Node* new_value = remove_private(node);//returns one up ( parent of deletion )
    if(new_value->value != 0){
        check_after_remove(removed_black,new_value, last_value_left, last_value_right); 
    }else{delete new_value;}
    
}