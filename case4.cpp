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
    Node* root = new Node(45);
    root->left = new Node(25);
    root->right = new Node(65);
    root->left->left = new Node(15);
    root->left->right = new Node(35);
    root->right->left = new Node(55);
    root->right->right = new Node(75);
    root->left->right->left = new Node(30);
    root->right->left->right = new Node(60);

    cout << "Before: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    //===================Successor===================
    // // Case 4: delete a node with TWO children.
    // // 1. search for value
    // Node* cur = root;
    // int key = 25;
    // while (cur != nullptr && cur->data != key) {
    //     if (key < cur->data) cur = cur->left;
    //     else                 cur = cur->right;
    // }
    // // 2. find the inorder successor: right once, then left as far as possible
    // Node* parent = cur;
    // Node* succ = cur->right; 
    // while (succ->left != nullptr) {
    //     parent = succ;
    //     succ = succ->left;
    // }
    // // 3. copy the successor's value into the node
    // cur->data = succ->data; 
    // // 4. remove the successor node (it has no left child)
    // if (parent == cur)
    //     parent->right = succ->right; 
    // else
    //     parent->left = succ->right;
    // delete succ;
    //===============================================

    //==================Predecessor==================
    // Case 4: delete a node with TWO children.
    // 1. search for value
    Node* cur = root;
    int key = 25;
    while (cur != nullptr && cur->data != key) {
        if (key < cur->data) cur = cur->left;
        else                 cur = cur->right;
    }
    // 2. find the inorder predecessor: left once, then right as far as possible
    Node* parent = cur;
    Node* pred = cur->left; 
    while (pred->right != nullptr) {
        parent = pred;
        pred = pred->right;
    }
    // 3. copy the predecessor's value into the node
    cur->data = pred->data; 
    // 4. remove the predecessor node (it has no right child)
    if (parent == cur)
        parent->left = pred->left;
    else
        parent->right = pred->left;
    delete pred;
    //===============================================

    cout << "After: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    freeTree(root);

    return 0; 
}