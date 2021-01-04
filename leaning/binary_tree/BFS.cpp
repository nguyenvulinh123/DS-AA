#include <iostream>
#include <math.h>
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

int getHeight (Node * root) {
    if (root == nullptr)
        return 0;
    return max (getHeight(root->left), getHeight(root->right)) + 1;
}

void printf_at_level (Node * root, int level) {
    if (root == nullptr) {
        return;
    }
    if (level == 1) {
        printf ("%d\t", root->data);
    } 
    else {
        printf_at_level (root->left, level - 1);
        printf_at_level (root->right, level - 1);
    }
}

void BFS (Node * root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; ++i) {
        printf_at_level (root, i);
    }
}

void BFS2 (Node * root) {
    queue<Node *> queue;
    if (root == nullptr) 
        return;
    queue.push(root);
    while (!queue.empty()) {
        Node * tmp = queue.front();
        printf ("%d\t", tmp->data);
        queue.pop();
        if (tmp->left) 
            queue.push(tmp->left);
        if (tmp->right)
            queue.push(tmp->right);
    }
}

int main (int argc, char * argv[]) {
    Node * n1 = new Node (1);
    n1->left = new Node (2);
    n1->right = new Node (3);
    n1->right->left = new Node (4);

    printf ("Height of tree : %d\n", getHeight(n1));
    BFS (n1);
    printf ("\n");
    printf_at_level(n1, 3);
}