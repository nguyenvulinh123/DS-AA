#include <iostream>
#include <queue>

struct Node {
    int data;
    Node * left;
    Node * right;
    Node (int i) {
        data = i;
        left = nullptr;
        right = nullptr;
    }
};

int height (Node * root) {
    if (root == nullptr) 
        return 0;
    else {
        int height_left = height (root->left) + 1;
        int height_right = height (root->right) + 1;
        return (height_left > height_right )? height_left : height_right; 
    } 
}

void print_at_given_order (Node * root, int level) {
    if (root == nullptr) 
        return;
    if (level == 1)
        printf ("%d\t", root->data);
    else {
        print_at_given_order(root->left, level - 1);
        print_at_given_order(root->right, level - 1);        
    }
}

void print_level_order_1 (Node * root) {
    int hei = height(root);
    for (int i = 1; i <= hei; ++i) {
        print_at_given_order(root, i);
    }
}

void print_level_order_2 (Node * root) {
    if (root == nullptr)
        return;
    std::queue <Node *> _queue;
    _queue.push (root); 
    while (!_queue.empty()) {
        Node * node = _queue.front();
        printf ("%d\t", node->data);
        if (node->left)
            _queue.push(node->left);
        if (node->right)
            _queue.push(node->right);
        _queue.pop();
    }
}

void insert_key_in_level_order (Node * root, int key) {
    if (root == nullptr)
        root = new Node (key);
    std::queue <Node *> _queue;
    _queue.push(root);
    while (!_queue.empty()) {
        Node * node = _queue.front();
        if (node->left)
            _queue.push(node->left);
        else {
            node->left = new Node(key);
            return;
        }
        if (node->right)
            _queue.push(node->right);
        else {
            node->right = new Node(key);
            return;
        }
        _queue.pop();
    }
    
}

void print_inorder (Node * root) {
    if (root == nullptr) 
        return;
    print_inorder(root->left);
    printf ("%d\t", root->data);
    print_inorder(root->right);
}

void deletion_in_binary_tree(Node * root) {
    
}

int main (int argc, char* argv[]) {
    Node * n1 = new Node (1);
    n1->left = new Node (3);
    n1->right = new Node (6);
    n1->left->left = new Node (4);
    n1->left->right = new Node (5);
    insert_key_in_level_order(n1, 7);
    print_inorder (n1);
}