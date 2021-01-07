#include <iostream>
#include <queue>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node * right;
    Node (int i) {
        data = i;
        left = right = nullptr;
    }
};

Node * search (Node * root, int key) {
    if (root == nullptr || root->data == key)
        return root;
    if (key < root->data)
        return search (root->left, key);
    return search (root->right, key);
}   

Node* Insert (Node * root, int data) {
    if (root == nullptr)
        return new Node (data);  
    if (data < root->data)
        root->left = Insert (root->left, data);
    if (data > root->data)
        root->right =  Insert (root->right, data);
    return root;
}

void BFS (Node * root) {
    if (!root) 
        return;
    queue<Node *> queue;
    queue.push (root);
    while (!queue.empty()){
        Node * temp = queue.front();
        queue.pop();
        printf ("%d\t", temp->data);
        if (temp->left)
            queue.push (temp->left);
        if (temp->right)
            queue.push (temp->right);
    }
    
}

int main (int argc, char* argv[]) {
    Node * root = new Node (1);
    Insert(root, 2);
    Insert(root, 3);
    Insert(root, 4);
    Insert(root, 5);
    Insert(root, 6);
    Insert(root, 7);
    Insert(root, 8);
    Insert(root, 9);
    Insert(root, 10);
    Insert(root, 11);
    BFS(root);
    printf ("\n-----------------\n");
    Node * temp1 = search(root, 3);
    if (temp1) 
        printf ("found key 3\n");
    else 
        printf ("counld'nt found key 3");
    Node * temp2 = search(root, 13);
    if (temp2) 
        printf ("found key 13");
    else 
        printf ("counld'nt found key 13");
    
}