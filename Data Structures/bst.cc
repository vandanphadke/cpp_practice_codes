#include<iostream>
using namespace std;

struct bst_node {
  int data;
  bst_node *left;
  bst_node *right;
};

class bst {
private:
  bst_node *root;

  void inorder_traversal(bst_node* node){
    if (node == NULL) return;
    inorder_traversal(node -> left);
    cout << node -> data;
    inorder_traversal(node -> right);
  }


public:
  bst() {
    root = NULL;
  }

  void inorder_traversal() {
    inorder_traversal(root);
    cout << endl;
  }

  bool search(int key){
    bst_node *current = root;
    while (current != NULL){
      if (current -> data == key) {
        return true;
      }
      else if (current -> data > key) {
        current = current -> left;
      }
      else {
        current = current -> right;
      }
    }
    return false;
  }

  int minimum(){
    bst_node *current = root;
    while(current -> left != NULL) current = current -> left;
    return current -> data;
  }

  int maximum(){
    bst_node *current = root;
    while(current -> right != NULL) current = current -> right;
    return current -> data;
  }

  void insert(int key){
    bst_node *y = NULL;
    bst_node *x = root;
    bst_node *new_node = new bst_node;
    new_node -> data = key;

    while (x != NULL) {
      y = x;
      if (key < (x -> data)) x = x -> left;
      else x = x -> right;
    }

    if (y == NULL) {
      this -> root = new_node;
    } else if (key < (y -> data)) {
      y -> left = new_node;
    } else {
      y -> right = new_node;
    }
  }
};

int main(int argc, char const *argv[]) {
  bst bst_obj;
  bst_obj.insert(3);bst_obj.insert(2);bst_obj.insert(1);bst_obj.insert(5);
  bst_obj.insert(4);
  cout << bst_obj.minimum() << endl;
  cout << bst_obj.maximum() << endl;
  return 0;
}
