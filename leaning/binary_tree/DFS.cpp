#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node (int in) {
        data = in;
        left = nullptr;
        right = nullptr;
    }
};

void DFS (Node * root) {
    if (root == nullptr) 
        return;
    DFS(root->left);
    printf ("%d\t", root->data);
    DFS(root->right);
}

void printf_all_leaves (Node * root) {
    if (root == nullptr) 
        return;
    if (root->left == nullptr && root->right == nullptr)
        printf ("%d\t", root->data);
    printf_all_leaves(root->left);
    printf_all_leaves(root->right);
}

unsigned int height (Node * root) {
    if (root == nullptr)
        return 0;
    unsigned int l_height = height (root->left);
    unsigned int r_height = height (root->right);
    return l_height > r_height ? l_height + 1 : r_height + 1;
}

void DFS_InOrder_UisngStack (Node * root) {
    if (root == nullptr) 
        return;
    stack<Node *> stack;
    Node * current = root;
    while (current || !stack.empty()) {
        while (current) {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        printf ("%d\t", current->data);
        stack.pop();
        current = current->right;
    }
}
void DFS_PerOrder_UsingStack (Node * root) {
    if (root == nullptr) {
        return;
    }
    stack<Node *> stack;
    Node * cur = root;
    while (cur || !stack.empty()) {
        while (cur) {
            stack.push (cur);
            cur = cur->left;
        }
        cur = stack.top();
        printf ("%d\t", cur->data);
        stack.pop();
        cur = cur->right;
    }
}

unsigned int count_node (Node * root) {
    if (root == nullptr)
        return 0;
    else 
        return count_node (root->left) + count_node(root->right) + 1;
}
unsigned int max (unsigned int s1, unsigned int s2) {
    return s1 > s2 ? s1 : s2;
}

unsigned int diameter(Node * root) {
    if (root == nullptr)
        return 0;
    unsigned int l_height = height (root->left);
    unsigned int r_height = height (root->right);

    unsigned int l_diameter = diameter (root->left);
    unsigned int r_diameter = diameter (root->right);

    return max (l_height + r_height + 1, max (l_diameter, r_diameter));
}

int diameter2 (Node * root, int * height) {
    int lh = 0, rh = 0;
    int l_diameter, r_diameter = 0;
    if (root == nullptr)  {
        *height = 0;
        return 0;
    }
    l_diameter = diameter2 (root->left, &lh);
    r_diameter - diameter2 (root->right, &rh);
    *height = max (lh, rh) + 1;
    return max (lh + rh + 1, max (l_diameter, r_diameter));
}

void height2 (Node * root, int * height) {
    int lh = 0, rh = 0;
    if (root == nullptr) {
        *height = 0;
    } else {
    height2 (root->left, &lh);
    height2 (root->right, &rh);
    *height = max (lh, rh) + 1;
    }
}

void DFS_PreOrder (Node * root) {
    if (root == nullptr){
        return;
    }
    printf ("%d\t", root->data);
    DFS_PreOrder (root->left);
    DFS_PreOrder (root->right);
}

void DFS_PreOrderWithoutRecursion (Node * root) {
    if (root == nullptr)
        return;
    stack<Node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        Node * cur = stack.top();
        printf ("%d\t", cur->data);
        stack.pop();
        if (cur->right)
            stack.push (cur->right);
        if (cur->left)
            stack.push (cur->left);
    }
    
}

void DFS_PostOrder (Node * root) {
    if (root == nullptr) {
        return;
    }
    DFS_PostOrder (root->left);
    DFS_PostOrder (root->right);
    printf ("%d\t", root->data);
}

int main(int argc, char* argv[]) {
    Node * n1 = new Node (1);
    n1->left = new Node (2);
    n1->left->right = new Node (3);
    n1->right = new Node (4);
    n1->right->left = new Node (5);
    n1->right->left->right = new Node (6);
    DFS_PostOrder (n1);
}