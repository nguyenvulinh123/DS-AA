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
   
    }
    const Comparable & findMax () const {
   
    }   
    bool contains (const Comparable &rhs) const {
        return false;
    }
    bool isEmpty() const {
        return false;
    }
    void printfTree (std::ostream &out = std::cout) {

    }
    void makeEmpty() {

    }
    void insert (const Comparable & rhs) {

    }
    void insert (Comparable &&rhs) {

    }
    void remove (const Comparable &rhs) {

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
    bool contains (const Comparable & rhs, BinarySearchTree *& t) const {
        return -1;
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
