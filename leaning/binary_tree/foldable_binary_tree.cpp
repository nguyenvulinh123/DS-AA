#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node(int in) {
        data = in;
        left = nullptr;
        right = nullptr;
    }
};

bool isStructSame (Node * node1, Node * node2) {
    if (node1 == nullptr && node2 == nullptr) 
        return true;
    if (node1 != nullptr && node2 != nullptr && isStructSame(node1->left, node2->left) && isStructSame (node1->right, node2->right))
        return true;
    return false;
}

bool isMirror (Node * node1, Node * node2) {
    if (node1 == nullptr && node2 == nullptr) 
        return true;
    if (node1 == nullptr || node2 == nullptr)
        return false;
    if (isMirror(node1->left, node2->right) && isMirror(node1->right, node2->left))
        return true;
    return false;
}

bool isFoldableTree(Node * root) {
    if (root == nullptr)
        return true;
    return isMirror(root->left, root->right);
}

int main (int argc, char * argv[ ]) {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    printf("isFoldableTree: %d\n", isFoldableTree(root));
}