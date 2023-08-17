  void RedBlackTree::inOrder(int min, int max) {
    inOrder(root,min,max);
  }
int ok = 0;
void RedBlackTree::inOrder(Node* node, int min, int max) {
    // if (node == NULL) {
    //   return;
    // }
    // if(node->left)if(node->left->value >= min){inOrder(node->left,min,max);}
    // cout<<node->value<<" ";
    // if(node->right)if(node->right->value <= max ){inOrder(node->right,min,max);}

    if (node == NULL) {
      return;
    }
    inOrder(node->left, min,max);
    if(node->value >= min && node->value <= max){ok = 1;fout << node->value << " ";}
    inOrder(node->right, min, max);
    if(ok == 1){fout<<endl;}
    ok = 0;
  }