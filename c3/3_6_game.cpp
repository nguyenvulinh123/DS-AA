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
    CircleLinkedList () : size(0) { head = nullptr;}
    ~CircleLinkedList () {
        if (head->next == head)
        {
            delete head;
        } else {
            Node<T> * del = head;
            Node<T> * tmp = head;
            while (tmp != head)
            {
                del = tmp;
                tmp = tmp->next;
                delete del;
            }
        }
    }
    void insert (T t) {
        ++size;
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
    void erase () {
        --size;
    }
    private:
    Node<T> * head;
    unsigned size;
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