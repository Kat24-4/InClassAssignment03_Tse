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

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) {
        cout << "Tree is empty: nothing to delete" << endl;
        return root;
    }
    // search for value, remember it's parent 
    Node* cur = root;
    Node* parent = nullptr;
    while (cur != nullptr && cur->data != key) {
        parent = cur;
        if (key < cur->data) cur = cur->left; 
        else                 cur = cur->right; 
    } 
    if (cur == nullptr) {
        // Case 5: the key is not in the tree.
        cout << key << " is not in the tree: nothing to delete" << endl;
    } else if (cur == root) {
        // Case 1: delete the root. It has two children.
        // find the inorder successor: the smallest value in the right subtree
        parent = root;
        Node* succ = root->right; // go right once 
        while (succ->left != nullptr) { // then left as far as possible
            parent = succ;
            succ = succ->left; 
        }
        // copy the successor's value into the root
        root->data = succ->data; 
        // remove the successor node (it has no left child)
        if (parent == root)
            parent->right = succ->right;
        else
            parent->left = succ->right; 
        delete succ;
    } else if ((cur->left == nullptr) && (cur->right == nullptr)) {
        // Case 2: delete a leaf . It has no children.
        // unlink it from its parent and free it
        if (parent->left == cur) parent->left = nullptr;
        else                     parent->right = nullptr;
        delete cur;
    } else if ((cur->left == nullptr) || (cur->right == nullptr)) {
        // Case 3: delete a node with ONE child.
        // its only child takes its place
        Node* child = (cur->left != nullptr) ? cur->left : cur->right;
        if (cur == root)              root = child; 
        else if (parent->left == cur) parent->left = child;
        else                          parent->right = child; 
        delete cur;
    } else {
        // Case 4: delete a node with TWO children.
        // find the inorder successor: right once, then left as far as possible
        parent = cur;
        Node* succ = cur->right; 
        while (succ->left != nullptr) {
            parent = succ;
            succ = succ->left;
        }
        // copy the successor's value into the node
        cur->data = succ->data; 
        // remove the successor node (it has no left child)
        if (parent == cur)
            parent->right = succ->right; 
        else
            parent->left = succ->right;
        delete succ;
    }

    return root; 
}

int main() {
    // Tree T
    Node* root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    //===============Delete 40===============
    cout << "====Delete 40====" << endl;
    cout << "Before: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    root = deleteNode(root, 40);

    cout << "After: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    //=======================================

    //===============Delete 10===============
    cout << endl << "====Delete 10====" << endl;
    cout << "Before: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    root = deleteNode(root, 10);

    cout << "After: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    //=======================================

    //===============Delete 60===============
    cout << endl << "====Delete 60====" << endl;
    cout << "Before: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    root = deleteNode(root, 60);

    cout << "After: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    //=======================================

    //===============Delete 75===============
    cout << endl << "====Delete 75====" << endl;
    cout << "Before: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    
    root = deleteNode(root, 75);

    cout << "After: ";
    printInorder(root);
    cout << "\t(root = " << root->data << ")";
    cout << endl;
    //=======================================
    
    freeTree(root);

    return 0;
}