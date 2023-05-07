#include <iostream>
#include <queue>

using namespace std;

class Bst {
		class Node {
			public:
				int value;
				Node* left;
				Node* right;
				Node* parent;
			
				Node(int val) {
					value = val;
				  	left = NULL;
					right = NULL;
					parent = NULL;
				}

				void print_node() { 
					
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

				}

		};
		int size_;
		Node* root_;

		Node* insert_(Node* node, int val);
		Node* find_(Node* node, int val);
		Node* min_(Node* node);
		Node* max_(Node* node);
		Node* succ_(Node* node);

	public:
		Bst() {
			size_ = 0;
			root_ = NULL;
		}

		void insert(int val);
		bool find(int val);
		int min();
		int max();
		int succ(int val);
		int pred(int val);
		void del(int val);

		void print();
		bool empty();
};

Bst::Node* Bst::insert_(Node* node, int val) {

	if(node == NULL){node = new Node(val);}
	else {
		if(val <= node->value){
			node->left = insert_(node->left, val);
			node->left->parent = node;
		}else
		{
			node->right = insert_(node->right,val);
			node->right->parent = node;
		}
		
	}
	return node;

}

void Bst::insert(int val) {

	root_ = insert_(root_, val);
}

Bst::Node* Bst::find_(Node* node, int val) {
	if(node == NULL)return NULL;

	if(val == node->value){
		return node;
	}
	else if(val <= node->value )
	{
		return find_(node->left, val);
		;
	}else{
		return find_(node->right,val);
	}
}

bool Bst::find(int val) {

	Node* found = find_(root_, val);
	if(found){return true;}else {return false;}
	
}

Bst::Node* Bst::min_(Node* node) {
	if(node->left == NULL) { return node; }

	return min_(node->left);
	
};

int Bst::min() {
	Node* min = min_(root_);
	if(min){return min->value;}
	else return -10000000;
};

Bst::Node* Bst::max_(Node* node) {	
	if(node->right == NULL) { return node; }

	return max_(node->right);
	
};

int Bst::max() {
	Node* max = max_(root_);
	if(max){return max->value;}
	else return 10000000;
};

Bst::Node* Bst::succ_(Node* node) {
	if(node->right){//cazul in care mergem in jos
		Node* temp = node->right;
		while(temp){
			if(temp->left){
				temp = temp->left;
			}else{return temp;}
		}
	}else{
		if(node == root_){return node;}
		Node* temp = node->parent;

		do{
			if(temp->value > node->value){return temp;}
			else {temp = temp->parent;}
			
		}while(!temp->parent);	
	}
};

int Bst::succ(int val) {
	
	Node* node = find_(root_,val);
	Node* succ = succ_(node);

	return succ->value;
};

int Bst::pred(int val) {
};

void Bst::del(int val) {
};

void Bst::print() {
	queue<Node*> to_visit;
	if (empty()) {
		throw invalid_argument("Nothing to print, tree empty.");
	} else {
		to_visit.push(root_);
		Node* current = root_;
		cout << "----------print--";
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

bool Bst::empty() {
	if (root_ == NULL) {
		return true;
	} else { 
		return false; 
	}
}

int main() {

	Bst tree;

	tree.insert(15);
	tree.insert(6);
	tree.insert(18);
	tree.insert(20);
	tree.insert(17);
	tree.insert(3);
	tree.insert(7);
	tree.insert(2);
	tree.insert(4);
	tree.insert(13);
	tree.insert(9);

	tree.print();
	
	cout << tree.find(9);

	cout << endl << "Min: " << tree.min() << endl;
	cout << "Max: " << tree.max() << endl << endl;

	cout << "Successor of 13 is " << tree.succ(13) << endl;
	cout << "Successor of 15 is " << tree.succ(15) << endl;
	cout << "Successor of 9 is " << tree.succ(9) << endl;
	cout << "Successor of 4 is " << tree.succ(4) << endl;
	//cout << "Successor of 17 is " << tree.succ(17) << endl;
	////cout << "Successor of 20 is " << tree.succ(20) << endl;
	//cout << endl;
	//cout << "Predecessor of 15 is " << tree.pred(15) << endl;
	//cout << "Predecessor of 6 is " << tree.pred(6) << endl;
	//cout << "Predecessor of 17 is " << tree.pred(17) << endl;
	////cout << "Predecessor of 2 is " << tree.pred(2) << endl;
	
	//tree.del(15);
	//tree.print();

	return 0;
}
