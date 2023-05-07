Node* RedBlackTree::find_private(Node* node, int val) {
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

bool RedBlackTree::find(int val) {

	Node* found = find_private(root, val);
	if(found){return true;}else {return false;}
	
}