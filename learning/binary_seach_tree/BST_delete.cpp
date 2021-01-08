#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node (int i) {
        data = i;
        left = right = nullptr;
    }
};

Node * insert (Node * root, int key) {
    if (root == nullptr)
        return new Node (key);
    if (key < root->data)
        root->left = insert (root->left, key);
    else
        root->right = insert (root->right, key);
    return root;
}

void BFS (Node * root) {
    if (root == nullptr)
        return;
    queue<Node *> queue;
    queue.push (root);
    while (!queue.empty()) {
        Node * temp = queue.front();
        queue.pop();
        printf ("%d\t", temp->data);
        if (temp->left)
            queue.push (temp->left);
        if (temp->right)
            queue.push (temp->right);
    }
}

Node * findMinNodes (Node * root) {
    Node * temp = root;
    while (temp && temp->left) {
        temp = temp->left;
    }
    return temp;
}

void DFS_inorder (Node * root) {
    if (!root)
        return;
    DFS_inorder (root->left);
    printf ("%d\t", root->data);
    DFS_inorder (root->right);
}

Node * delete_node (Node * root, int key) {
    if (root == nullptr)
        return root;
    if (key < root->data) {
        root->left = delete_node (root->left, key);
    } else if (key > root->data) {
        root->right = delete_node (root->right, key);
    } else {
        if (root->left == nullptr) {
            Node * temp = root->right;
            delete (root);
            return temp;
        } else if (root->right == nullptr) {
            Node * temp = root->left;
            delete (root);
            return temp;
        }
        Node * temp = findMinNodes (root->right);
        root->data = temp->data;
        root->right = delete_node (root->right, temp->data);
    }
    return root;
}

int main (int argc, char * argv[]) {
    Node * n1 = new Node (100);
    insert (n1, 1);
    insert (n1, 0);
    insert (n1, -10);
    insert (n1, 3);
    insert (n1, 5);
    insert (n1, 20);
    DFS_inorder (n1);
    printf ("\n-------------------------------\n");
    delete_node(n1, 0);
    delete_node(n1, 5);
    DFS_inorder (n1);

}