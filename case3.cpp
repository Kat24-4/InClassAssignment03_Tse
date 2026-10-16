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
    // Tree T
    // Node* root = new Node(40);
    // root->left = new Node(20);
    // root->right = new Node(60);
    // root->left->left = new Node(10);
    // root->left->right = new Node(30);
    // root->right->left = new Node(50);
    // root->right->right = new Node(70);

    // Tree P
    // Node* root = new Node(45);
    // root->left = new Node(25);
    // root->right = new Node(65);
    // root->left->left = new Node(15);
    // root->left->right = new Node(35);
    // root->right->left = new Node(55);
    // root->right->right = new Node(75);
    // root->left->right->left = new Node(30);
    // root->right->left->right = new Node(60);

    //Question 4 Tree
    Node* root = new Node(10);
    root->right = new Node(20);
    root->right->right = new Node(30);

    cout << "Before: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    // Case 3: delete a node with ONE child.
    // 1. search for value, remembering its parent
    Node* parent = nullptr;
    Node* cur = root;
    int key = 10;
    while (cur != nullptr && cur->data != key) {
        parent = cur;
        if (key < cur->data) cur = cur->left;
        else                 cur = cur->right;
    }
    // 2. its only child takes its place
    Node* child = (cur->left != nullptr) ? cur->left : cur->right;
    if (cur == root)              root = child; 
    else if (parent->left == cur) parent->left = child;
    else                          parent->right = child; 
    delete cur;

    cout << "After: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    freeTree(root);

    return 0; 
}