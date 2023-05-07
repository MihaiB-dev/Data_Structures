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

int RedBlackTree::succ(int val) {
	
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

int RedBlackTree::pred(int val) {
	
	Node* node = find_private(root,val);
	Node* pred = predecessor(node);
	if(pred->value != 0){return pred->value;}
	return 0;
	
};

