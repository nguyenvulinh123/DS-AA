#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
    Node * nextRight;
    Node (int in) {
        data = in;
        left = right = nextRight = nullptr;
    }
};

void connect_all_node_with_same_level (Node * root) {
    if (root == nullptr)
        return;
    queue<Node *> queue;
    queue.push(root);

    while (!queue.empty()) {
        int size = queue.size();
        Node * tmp = nullptr;
        for (int i = 0; i < size; ++i) {
            Node * prev = tmp;
            tmp = queue.front();
            queue.pop(); 
            if (i > 0)
                prev->nextRight = tmp;
            if (tmp->left)
                queue.push(tmp->left);
            if (tmp->right)
                queue.push(tmp->right);
        } 
        tmp->nextRight = nullptr;
    }
}

int main(int argc, char* argv[]) {
    Node * n1 = new Node (1);
    n1->left = new Node (2);
    n1->right = new Node (3);
    n1->left->right = new Node (4);
    n1->right->right = new Node (6);

    connect_all_node_with_same_level(n1);

    Node * tmp = n1->left->right; 
    while (tmp)
    {
        printf ("%d\t", tmp->data);
        tmp = tmp->nextRight;
    }
    
}