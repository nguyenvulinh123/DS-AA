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
        List () : size(0) {
            head = nullptr;
        }
        ~List() {
            Node<T> *tmp;
            while (head) 
            {
                tmp = head;
                head = head->next;
                delete tmp;
            }
        }
        void push_back (Node<T> *& node)
        {
            size++;
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
            if (size - start_index < 2)
            {
                std::cout << "Could not swap!\n";
                return;   
            }
            if (start_index == 0)
            {
                //N1 -> N2
               Node<T> * tmp = head->next;
               head->next = tmp->next;
               tmp->next = head;  
               head = tmp;
            } else {
                // tmp -> N1 -> N2 ->
                Node<T> * tmp = head;
                while (start_index > 1)
                {
                    start_index--;
                    tmp = tmp->next;
                }
                Node<T> * node = tmp->next;
                tmp->next = node->next;
                node->next = node->next->next;
                tmp->next->next = node;
            }
        }
    private:
        Node<T> * head;
        unsigned size;
};

int main (int argc, char* argv[]) {
    List<int> L;
    Node<int> * node;
    for (int i = 0; i < 10; ++i)
    {
        node = new Node<int> (i);
        L.push_back(node);
    }
    L.swap_two_adjacent(4);
    L.print();
}