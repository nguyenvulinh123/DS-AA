#include <iostream>
#include <list>
template <class T>
struct Node {
    T data;
    Node* next;
    Node (T t) : data(t) {
        next = nullptr;
    }
};
template <typename T>
class List {
    public:
        List () {
            head = nullptr;
        }
        void push_back (Node<T> *& node)
        {
            if (!head) {
                head = node;
            } else {
                Node<T>* tmp = head;
                while (tmp->next) {
                    tmp = tmp->next;
                }
                tmp->next = node;
            }
        }
        void print () 
        {
            std::cout << "print list: \n";
            Node<T> *tmp = head;
            while (tmp)
            {
                std::cout << tmp->data << "\t";
                tmp = tmp->next;
            }
            std::cout << std::endl;
        }
        void swap_two_adjacent (int start_index) {

        }
    private:
        Node<T> * head;
};

int main (int argc, char* argv[]) {
    List<int> L;
}