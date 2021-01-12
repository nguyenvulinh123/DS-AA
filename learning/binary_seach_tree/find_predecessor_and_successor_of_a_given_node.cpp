#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int in) {
        data = in;
        right = left = nullptr;
    }
};

Node * find_leftest_node (Node * root) {
    if (root == nullptr)
        return root;
    Node * temp = root;
    while (temp->left)
    {
        temp = temp->left;
    }
    return temp;
}

Node * find_rightest_node (Node * root) {
    if (root == nullptr)
        return root;
    Node * temp = root;
    while (temp->right)
    {
        temp = temp->right;
    }
    return temp;
}

Node * BST_insert (Node * root, int data) {
    if (root == nullptr)
        return new Node (data);  
    if (data < root->data)
        root->left = BST_insert (root->left, data);
    if (data > root->data)
        root->right =  BST_insert (root->right, data);
    return root;
}

void find_perdecessor_and_successor_of_a_node (Node * root, Node *& predecessor, Node *& scucessor,int key) {
    if (root == nullptr) {
        return;
    }
    if (root->data == key) {
        if (root->left != nullptr) {
            Node * temp = root->left;
            while (temp->right) {
                temp = temp->right;
            }
            predecessor = temp;
        }
        if (root->right != nullptr) {
            Node * temp = root->right;
            while (temp->left) {
                temp = temp->left;
            }
            scucessor = temp;
        }
        return;
    }
    if (key < root->data) {
        scucessor = root;
        find_perdecessor_and_successor_of_a_node (root->left, predecessor, scucessor, key);
    } else {
        predecessor = root;
        find_perdecessor_and_successor_of_a_node (root->right, predecessor, scucessor, key);
    }
}

void DFS_inorder (Node * root) {
    if (root == nullptr)
        return;
    DFS_inorder (root->left);
    printf ("%d\t", root->data);
    DFS_inorder (root->right);
}

int main (int argc, char* argv[]) {
    Node * root = new Node (10);
    BST_insert(root, 8);
    BST_insert(root, 4);
    BST_insert(root, 3);
    BST_insert(root, 5);
    BST_insert(root, 2);
    BST_insert(root, 1);
    BST_insert(root, 7);
    DFS_inorder (root);
    printf ("\n");
    Node * predecessor, * successor;
    find_perdecessor_and_successor_of_a_node(root, predecessor, successor, 5);
    printf ("predecessor = [%d], sucessor = [%d]\n", predecessor->data, successor->data);
}