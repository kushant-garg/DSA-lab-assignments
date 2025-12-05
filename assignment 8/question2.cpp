#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int d) { data = d; left = right = NULL; }
};

// Insert
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data) root->left = insertBST(root->left, key);
    else if (key > root->data) root->right = insertBST(root->right, key);
    return root;
}

// Recursive Search
Node* searchRec(Node* root, int key) {
    if (!root || root->data == key) return root;
    if (key < root->data) return searchRec(root->left, key);
    return searchRec(root->right, key);
}

// Iterative Search
Node* searchIter(Node* root, int key) {
    while (root) {
        if (root->data == key) return root;
        else if (key < root->data) root = root->left;
        else root = root->right;
    }
    return NULL;
}

// Min
Node* minNode(Node* root) {
    while (root && root->left) root = root->left;
    return root;
}

// Max
Node* maxNode(Node* root) {
    while (root && root->right) root = root->right;
    return root;
}

// Inorder Successor
Node* inorderSuccessor(Node* root, Node* node) {
    if (node->right) return minNode(node->right);
    Node* succ = NULL;
    while (root) {
        if (node->data < root->data) {
            succ = root;
            root = root->left;
        } else root = root->right;
    }
    return succ;
}

// Inorder Predecessor
Node* inorderPredecessor(Node* root, Node* node) {
    if (node->left) return maxNode(node->left);
    Node* pred = NULL;
    while (root) {
        if (node->data > root->data) {
            pred = root;
            root = root->right;
        } else root = root->left;
    }
    return pred;
}