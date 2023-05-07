void Node::print_node() { 
					
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

void RedBlackTree::print() {
	queue<Node*> to_visit;
	if (empty()) {
		throw invalid_argument("Nothing to print, tree empty.");
	} else {
		to_visit.push(root);
		Node* current = root;
		cout << "----print----";
		while ( !to_visit.empty()) {
			current->print_node();
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