/*
Given a binary tree, delete a node from it by making sure that tree shrinks from the bottom (i.e. the deleted node is replaced by bottom most and rightmost node).
This different from BST deletion. Here we do not have any order among elements, so we replace with last element.
*/
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node (int input) {
        data = input;
        left = nullptr;
        right = nullptr;
    }
};

void print_inorder(Node * root) {
    if (root == nullptr)
        return;
    print_inorder(root->left);
    printf ("%d\t", root->data);
    print_inorder(root->right);
}

void delete_deepest_right_node (Node * root, Node * deepest_right) {
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node * node = queue.front();
        queue.pop();
        if (node == deepest_right) {
            node = nullptr;
            delete (deepest_right);
            return;
        }
        if (node->right) {
            if (node->right == deepest_right) {
                node->right = nullptr;
                delete(deepest_right);
                return;
            } else {
                queue.push(node->right);
            }
        }
        if (node->left) {
            if (node->left == deepest_right) {
                node->left = nullptr;
                delete(deepest_right);
                return;
            } else {
                queue.push(node->left);
            }
        }
    }
}

Node * deletion_a_node_in_binary_tree (Node * root, int key) {
    if (root == nullptr)
        return nullptr;
    if (root->left == NULL && root->right == NULL) { 
        if (root->data == key) 
            return nullptr; 
        else
            return root; 
    }
    Node * key_node = nullptr;
    Node * node = nullptr;
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        node = queue.front();
        queue.pop();
        if (node->data == key) {
            key_node = node;
        }
        if (node->left) {
            queue.push(node->left);
        }
        if (node->right) {
            queue.push (node->right);
        }
    }
    if (node != nullptr) {
        key_node->data = node->data;
        delete_deepest_right_node (root, node);
    }
    return root;
}

int main (int argc, char* argv[]) {
    Node * root = new Node(5);
    root->left = new Node(6);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(2);
    deletion_a_node_in_binary_tree(root, 1);
    print_inorder(root);
}