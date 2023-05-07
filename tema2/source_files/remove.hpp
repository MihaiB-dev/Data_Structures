// Node* RedBlackTree::remove_private(Node* node) {
//     //find the succesor
// 	if(node->right){//we are certain that we have a succesor.
// 		Node* succesor = node->right;
// 		while(succesor){
// 			if(succesor->left){
// 				succesor = succesor->left;
// 			}else{break;}
// 		}
//         //change the the node.
//         node->value = succesor->value;
//         node->black = succesor->black;

//         //delete the succesor.
//         if(succesor->left) // daca mai are noduri in stanga
//         {   
//             succesor->left->parent = succesor->parent;
//             succesor->parent->right = succesor->left;
//             Node* copy = succesor->left;
//             succesor = NULL;
//             size --;
//             return copy->parent;
//         }else{
//             if(succesor->right){ // daca mai are noduri in dreapta
//                 succesor->parent->right = succesor->right;
//                 succesor->right->parent = succesor->parent;
//                 Node* copy = succesor->right;
//                 succesor = NULL;
//                 size --;
//                 return copy->parent;
//             }else{ // daca este leaf
//                 if(succesor->isLeftChild){succesor->parent->left = NULL;}else{succesor->parent->right = NULL;}
                
//                 succesor = NULL;
//                 size--;
//                 return node;
//             }
            
//         }
        
//     }
//     if(node->left){//connect the left part to the parent of the node and disconnect the node.
//         node->left->parent = node->parent;
//         node->parent->right = node->left;
//         Node* copy = node->left;
//         node = NULL;
//         size --;
//         return copy->parent;
//     }else{//it's a leaf , we can disconnect it directly, minus for size.
//         if(node->isLeftChild){node->parent->left = NULL;} else {node->parent->right = NULL;}; 
//         Node* parent = node->parent;
//         node = NULL;
//         size--;
//         return parent; 
//     }
    

// };
void RedBlackTree::handleDoubleBlack(Node* node,bool isLeftChild)//first is parent of double black
{   //node->doublBlack = false;
    if(node==root){return;}
    if(node->right && 
        node->right->black == true && 
        ((node->right->left == NULL && node->right->right == NULL)
        ||(node->right->left->black == true && node->right->right->black == true)
        ||(node->right->left == NULL && node->right->right->black == true)
        ||(node->right->right == NULL && node->right->left->black == true)
        )
        && isLeftChild == true)
        {
            if(node->black == true)
            {   
                 isLeftChild = node->left->isLeftChild; 
                 handleDoubleBlack(node->parent,isLeftChild);
            }else{node->black = true;}
            
            node->right->black = false;//sibling red
        }
        if(node->left && 
        node->left->black == true &&
        ((node->left->left == NULL && node->left->right == NULL)
        ||(node->left->left->black == true && node->left->right->black == true)
        ||(node->left->left == NULL && node->left->right->black == true)
        ||(node->left->right == NULL && node->left->left->black == true)
        )
        && isLeftChild == false
        )
        {
            if(node->black == true){
                isLeftChild = node->right->isLeftChild; 
                handleDoubleBlack(node->parent,isLeftChild);
            }else{node->black = true;} 
            
            node->left->black = false; //sibling red
        }
    if(node->right && node->right->black == false && isLeftChild == true)
    {
        node->right->black = true;
        node->black = false; 
        leftRotate(node);
        //ADD
    }

    if(node->left && node->left->black == false && isLeftChild == false)
    {
        node->left->black = true;
        node->black = false;
        rightRotate(node);
        //ADD
    }
}


void RedBlackTree::check_before_remove(Node* node){
    if(node->black == false) // if the node is red, gust delete it
    {
        remove_private(node);
    }
    else // if node is black 
    {
        if(node->right && node->right->black == false){remove_private(node);return;}// if we have a child red we remove
        if(node->left && node->left->black == false){remove_private(node);return;}

        //DB part
        Node* parent_of_DB = node->parent;
        bool isLeftChild = node->isLeftChild;
        remove_private(node);

        //if DB's sibling is black, and bot of it's children are black :
        //remove DB
        //add black to it's parent
        // if p is red it becomes black
        // if p is black it becomes double black
        //make sibling red
        handleDoubleBlack(parent_of_DB,isLeftChild);
        //-------------------------------------------------


    }
}
void RedBlackTree::remove_private(Node *node){ // BST Basic remove method
    if(node->left == NULL && node->right == NULL){ // 0 child
        if(node->isLeftChild){
            node->parent->left = NULL;
        }else if(node->isLeftChild == false){
            node->parent->right = NULL;
            }
        delete node;
        
    }else
    if(node->left != NULL && node->right == NULL){ // 1 left child
        if(node->isLeftChild){
            node->parent->left = node->left; 
            node->left->parent= node->parent;
            }
        else{
            node->parent->right= node->left; 
            node->left->parent= node->parent;}
        node->left->black = node->black;
        delete node;
    }else
    if(node->right != NULL && node->left == NULL) // 1 right child
    {
        if(node->isLeftChild){
            node->parent->left = node->right;
            node->right->parent = node->parent;}
        else{
            node->parent->right = node->right;
            node->right->parent = node->parent;
        }
        node->right->black = node->black;
        delete node;
    }
    else
    if(node->right != NULL && node->left != NULL) // 2 children
    {
        Node* succesor = node->right;
		while(succesor){
			if(succesor->left){
				succesor = succesor->left;
			}else{break;}
		}
        //change the node.
        node->value = succesor->value;
        check_before_remove(succesor);
    }
}

void RedBlackTree::remove(int value){
    Node* node = find_private(root,value);

    check_before_remove(node);
}