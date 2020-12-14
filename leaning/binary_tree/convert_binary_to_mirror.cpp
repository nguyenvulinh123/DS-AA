#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node (int in) {
        data = in;
        left = nullptr;
        right = nullptr;
    }
};

void print_level_order (Node * root) {
    if (root == nullptr)
        return;
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node * tmp = queue.front();
        queue.pop();
        printf("%d\t", tmp->data);
        if (tmp->left)
            queue.push (tmp->left);
        if (tmp->right)
            queue.push (tmp->right);
    }
}

void print_in_order (Node * root) {
    if (root == nullptr)
        return;
    printf ("%d\t", root->data);
    print_in_order (root->left);
    print_in_order (root->right);
}

void convert_to_mirror (Node * root) {
    if (root == nullptr) 
        return;
    convert_to_mirror(root->left);
    convert_to_mirror(root->right);
    Node * tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}

int main (int argc, char * argv[]) {
    Node * root = new Node(1);
    root->left = new Node (2);
    root->right = new Node (3);
    root->left->left = new Node (4);
    root->left->left->left = new Node (5);
    // print_in_order(root);
    print_level_order(root);
    convert_to_mirror(root);
    printf("\n");
    print_level_order(root);
    return 0;
}



