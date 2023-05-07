void RedBlackTree::handleDoubleBlack(Node* node,bool isLeftChild)//first is parent of double black
{
    if(node==root){return;}
    //CASE 3 DB's sibling is black, and bot of it's children are black :
        //remove DB
        //add black to it's parent
        // if p is red it becomes black
        // if p is black it becomes double black
        //make sibling red

    //CASE 4 if Db's sibling is red:
    //swap colors of parent & it's sibling
    //rotate parent in Db direction
    //reply cases

    //CASE 5
    //db's sibing is black siblings chils who is far rom Db is black but
    //near child to Db is red :
    //swap colors of Db's sibling & siblings chil who is near to Db
    //rotate sibling in oposite direction to apply case 6
    if(node->right && 
        node->right->black == true && isLeftChild == true) //CASE 3
        {if((node->right->left == NULL && node->right->right == NULL)
        ||(node->right->left->black == true && node->right->right->black == true)
        ||(node->right->left == NULL && node->right->right->black == true)
        ||(node->right->right == NULL && node->right->left->black == true)
            )   
        { //CASE 3
            if(node->black == true)
            {   
                 isLeftChild = node->left->isLeftChild; 
                 handleDoubleBlack(node->parent,isLeftChild);
                 return;
            }else{node->black = true;}
            
            node->right->black = false;//sibling red
        } else if(node->right->left->black == false && node->right->right && node->right->right->black == true)
        {//CASE 5
            node->right->left->black = true;
            node->right->black = false;
            rightRotate(node->right);
        }

        }
        if(node->left && 
        node->left->black == true && isLeftChild == false)//CASE 3
        if((node->left->left == NULL && node->left->right == NULL)
        ||(node->left->left->black == true && node->left->right->black == true)
        ||(node->left->left == NULL && node->left->right->black == true)
        ||(node->left->right == NULL && node->left->left->black == true)
        ){//CASE 3
            if(node->black == true){
                isLeftChild = node->right->isLeftChild; 
                handleDoubleBlack(node->parent,isLeftChild);
                return;
            }else{node->black = true;} 
            
            node->left->black = false; //sibling red
        } else if(node->left->right->black = false && node->left->left && node->left->left->black == true )
        {//CASE 5
            node->left->right->black = true;
            node->left->black = false;
            leftRotate(node->left);
        }
    if(node->right && node->right->black == false && isLeftChild == true)
    {//CASE 4
        node->right->black = true;
        node->black = false; 
        leftRotate(node);

        handleDoubleBlack(node->left, isLeftChild);
        return;
    }

    if(node->left && node->left->black == false && isLeftChild == false)
    {//CASE 4
        node->left->black = true;
        node->black = false;
        rightRotate(node);

        handleDoubleBlack(node->right, isLeftChild);
        return;
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