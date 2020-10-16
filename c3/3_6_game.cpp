#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;
    explicit Node (T t)
    {
        data = t;
        next = nullptr;
    }
};
template <typename T>
class CircleLinkedList {
    public:
    CircleLinkedList () { head = nullptr;}
    ~CircleLinkedList () {}
    void insert (T t) {
        Node<T> *node = new Node<T> (t);
        if (!head){
            head = node;
            node->next = head;
        } else {
            Node<T> *tmp = head;
            while (tmp->next != head)
            {
                tmp = tmp->next;
            }
            tmp->next = node;
            node->next = head;
        }
    }
    void print () {
        printf ("CircleLinkedList = \t");
        if (head == nullptr){
            printf ("\n");
            return;
        }
        Node<T> *tmp = head;
        do {
            printf ("%d\t", tmp->data);
            tmp = tmp->next;
        } while (tmp != head);
        printf ("\n");
    }
    private:
    Node<T> * head;
};

int main(int argc, char* argv[])
{
    CircleLinkedList<int> cl;
    int input;
    do {
        printf ("Enter list element: \t");
        std::cin >> input;
        cl.insert(input);
    } while (input != -1);
    cl.print();
    return 0;
}