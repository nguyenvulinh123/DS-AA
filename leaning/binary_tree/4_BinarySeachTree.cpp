// infix to postfix
#include <iostream>

using std::cout;

template <typename Comparable>
class BinarySearchTree {
    public:
    BinarySearchTree () {

    }
    BinarySearchTree (const BinarySearchTree &rhs) {

    }
    BinarySearchTree (BinarySearchTree && rhs) {

    }
    ~BinarySearchTree () {

    }

    const Comparable & findMin () const {
        if (root == nullptr)
            return nullptr;
        BinaryNode * tmp = root;
        while (tmp->left) {
            tmp = tmp->left;
        }
        return tmp->element;
    }
    const Comparable & findMax () const {
        if (root == nullptr)
            return nullptr;
        if (root->right == nullptr)
            return root->element;
        return findMax (root->right);
    }   
    bool contains (const Comparable &rhs) const {
        return contains (rhs, root);
    }
    bool isEmpty() const {
        return false;
    }
    void printfTree (std::ostream &out = std::cout) {

    }
    void makeEmpty() {

    }
    void insert (const Comparable & rhs) {
        insert(rhs, root);
    }
    void insert (Comparable &&rhs) {
        insert (rhs, root);
    }
    void remove (const Comparable &rhs) {
        remove (rhs, root);
    }
    BinarySearchTree operator= (const BinarySearchTree &rhs) {

    }
    BinarySearchTree operator= (BinarySearchTree &&rhs) {

    }


    private:
    struct BinaryNode {
        Comparable element;
        BinaryNode * left;
        BinaryNode * right;
        BinaryNode (const Comparable &rhs, BinaryNode *lt, BinaryNode *rt) : element(rhs), left (lt), right (rt) {}
        BinaryNode (Comparable && rhs, BinaryNode *lt, BinaryNode *rt) : element (std::move(rhs)), left (lt), right (rt) {}
    };
    BinarySearchTree * root;

    void insert (const Comparable & comparable, BinarySearchTree *& t) {

    }
    void insert (Comparable && rhs, BinarySearchTree *& t) {

    }
    void remove (const Comparable rhs, BinarySearchTree *& t) {

    }
    BinaryNode * findMin (BinarySearchTree & t) const {

    }
    BinaryNode * findMax (BinarySearchTree & t) const {

    }
    bool contains (const Comparable & rhs, BinaryNode *& t) const {
        if (t == nullptr)
            return false;
        if (t->element == rhs) {
            return true;
        } else if (rhs < t->element) {
            return contains (rhs, t->right);
        } else {
            return contains (rhs, t->left);
        }
    }
    void makeEmpty(BinarySearchTree *& t) {

    }
    void printfTree (const Comparable & rhs, BinarySearchTree *& t) const {

    }
    BinaryNode * clone (BinaryNode *& t) const {

    }
};

int main (int argc, char * argv[]) {
    BinarySearchTree<int> b;
    return 0;
}
