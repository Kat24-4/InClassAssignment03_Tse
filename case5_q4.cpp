#include <iostream>
using namespace std; 

class Node {
    public:
        int data;
        Node* left;
        Node* right;
   
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
// Inorder (Left, Node, Right) prints a BST in sorted order
void printInorder(Node* node) {
    if (node == nullptr) return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
// Free every node (postorder: children before parent)
void freeTree(Node* node) {
    if (node == nullptr) return;
    freeTree(node->left);
    freeTree(node->right);
    delete node;
}

int main() {
    // Empty Tree
    Node* root = nullptr;

    cout << "Before: ";
    printInorder(root);
    if (root == nullptr) cout << "the tree is empty";
    else                 cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    //===================Not Found===================
    // Case 5: the key is not in the tree.
    Node* cur = root;
    int key = 25;
    while (cur != nullptr && cur->data != key) {
        if (key < cur->data) cur = cur->left; 
        else                 cur = cur->right; 
    } 
    if (cur == nullptr)
        cout << key << " is not in the tree: nothing to delete" << endl;
    //===============================================

    cout << "After: ";
    printInorder(root);
    if (root == nullptr) cout << "the tree is empty";
    else                 cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    freeTree(root);

    return 0; 
}