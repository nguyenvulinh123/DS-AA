/*
    In order tree (Left Root Right) traversal using stack
*/
#include <iostream>
#include <stack>
struct Node
{
    int data;
    Node * left;
    Node * right;
    Node (int in) {
        data = in;
        left = nullptr;
        right = nullptr;
    }
};

void print_in_order_tree_traversal_stack (Node * root) {
    if (root == nullptr)
        return;
    std::stack<Node *> stack;
    Node * current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }
        Node * tmp = stack.top();
        stack.pop();
        printf("%d\t", tmp->data);
        current = tmp->right;
    }

}

int main (int argc, char * argv[]) {
    struct Node *root = new Node(1); 
    root->left        = new Node(2); 
    root->right       = new Node(3); 
    root->left->left  = new Node(4); 
    root->left->right = new Node(5); 
    print_in_order_tree_traversal_stack(root);
}