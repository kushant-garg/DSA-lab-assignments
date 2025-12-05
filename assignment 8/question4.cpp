#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

bool isBSTUtil(Node* root, long long minVal, long long maxVal) {
    if (root == NULL)
        return true;

    if (root->data <= minVal || root->data >= maxVal)
        return false;

    return isBSTUtil(root->left, minVal, root->data) &&
           isBSTUtil(root->right, root->data, maxVal);
}

bool isBST(Node* root) {
    long long minLimit = -9223372036854775807LL - 1;
    long long maxLimit = 9223372036854775807LL;

    return isBSTUtil(root, minLimit, maxLimit);
}

int main() {
    Node* root = newNode(4);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(1);
    root->left->right = newNode(3);

    if (isBST(root))
        cout << "The tree IS a BST\n";
    else
        cout << "The tree is NOT a BST\n";

    return 0;
}
