#include <iostream>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node (int i){
        data = i;
        left = right = nullptr;
    }
};

bool print_accessors_by_given_node (Node * root, int data) {
    if (root == nullptr) {
        return false;
    }
    if (root->data == data) {
        return true;
    } if (print_accessors_by_given_node (root->left, data) || print_accessors_by_given_node (root->right, data)){
        printf ("%d\t", root->data);
        return true;
    }
    return false;
}

bool isIdentical (Node * n1, Node * n2) {
    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;
    if (n1->data == n2->data && isIdentical (n1->left, n2->left) && isIdentical(n1->right, n2->right)) {
        return true;
    }
    return false;
}

bool isSubTree (Node * T, Node * S) {
    if (T == nullptr)
        return false;
    if (S == nullptr)
        return true;
    if (isIdentical (T, S))
        return true;
    return isSubTree (T->left, S) || isSubTree (T->right, S);
}

int main (int argc, char * argv[]) {
    Node * root = new Node (1);
    root->left = new Node (2);
    root->right = new Node (3);
    root->left->right = new Node (4);
    root->left->right->left = new Node (6);
    print_accessors_by_given_node (root, 6);
}