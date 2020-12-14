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

bool check_continous_tree (Node * root) {
    if (root == nullptr)
        return false;
    queue<Node *> queue;
    queue.push(root);
    while (!queue.empty()) {
        Node * tmp = queue.front();
        queue.pop();
        if (tmp->left != nullptr) {
            if (abs(tmp->left->data - tmp->data) != 1) {
                return false;
            } else {
                queue.push(tmp->left);
            }
        }
        if (tmp->right != nullptr) {
            if (abs(tmp->right->data - tmp->data) != 1) {
                return false;
            } else {
                queue.push(tmp->right);
            }
        }
    }
    return true;
}

int main (int argc, char* argv[]) {
    Node * root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(4);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(5);

    cout << "check_true_continous : " << check_continous_tree(root) << flush;
}