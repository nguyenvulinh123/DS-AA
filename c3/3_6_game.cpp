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
    void erase (int index) {
        Node<T> *tmp = head;
        if (index == 0)
        {
            int tmp_size = size;
            while (tmp_size > 1) {
                --tmp_size;
                tmp = tmp->next;
            }
            tmp->next = tmp->next->next;
            tmp = head;
            head = head->next;
            delete tmp;
        } else {        
            while (index > 1){
                --index;
                tmp = tmp->next;
            }
            Node<T> * node = tmp->next;
            tmp->next = tmp->next->next;
            delete node;
        }
        --size;
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
    unsigned size;
};

int main(int argc, char* argv[])
{
    CircleLinkedList<int> cl;
    int N, M, key;
    printf ("Enter N people: ");
    scanf ("%d", &N);
    printf ("Enter M: ");
    scanf ("%d", &M);
    printf ("Enter %d element: ", N);
    for (int i = 0; i < N; ++i)
    {
        scanf ("%d", &key);
        cl.insert(key);
    }
    cl.erase(0);
    cl.print();
    return 0;
}