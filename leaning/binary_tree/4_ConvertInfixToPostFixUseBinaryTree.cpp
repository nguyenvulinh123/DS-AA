// infix to postfix
#include <iostream>
#include <stack>
#include <set>

using std::cout;
using std::stack;
using std::set;

template<typename T>
struct Node {
    T data;
    Node * left;
    Node * right;
    Node (T t) : data(t), left (nullptr), right (nullptr) {

    }
};
template<typename T> 
class BinaryTree {

};

bool isOperator (char c) {
    set <char> s {'+', '-', '*', '/', '%'};
    if (s.find (c) != s.end())
        return true;
    else 
        return false;
}

void convert_infix_to_posfix (char * s, unsigned length) {
    stack <int> st;
    char T1, T2;
    for (int i = 0; i < length; ++i) {
        if (isOperator (s[i])) {
            T1 = st.top();
            st.pop();
            T2 = st.top();
            st.pop();
        } else {
            st.push(s[i]);
        }
    }
}

int main (int argc, char * argv[]) {
    return 0;
}
