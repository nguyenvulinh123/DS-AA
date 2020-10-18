#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node *next;
    Node * prev;
    explicit Node (T t)
    {
        data = t;
        next = nullptr;
        prev = nullptr;
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
            node->next = node;
            node->prev = node;
            head = node;
        } else {
            Node<T> *tmp = head;
            while (tmp->next != head)
            {
                tmp = tmp->next;
            }
            tmp->next = node;
            node->next = head;
            node->prev = tmp;
            head->prev = node;
        }
    }
    void erase (int index) {
        printf ("erase element : %d\n", index);
        Node<T> *tmp = head;
        if (index == 0)
        {
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            head = tmp->next;
            delete tmp;
        } else {        
            while (index > 0){
                --index;
                tmp = tmp->next;
            }
            Node<T> * del = tmp;
            tmp->next->prev = tmp->prev;
            tmp->prev->next = tmp->next;
            delete del;
        }
        --size;
    }
    void print_by_next () {
        printf ("print_by_next CircleLinkedList = \t");
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
    void print_by_prev () {
        printf ("print_by_next CircleLinkedList = \t");
        if (head == nullptr){
            printf ("\n");
            return;
        }
        Node<T> *tmp = head;
        do {
            printf ("%d\t", tmp->data);
            tmp = tmp->prev;
        } while (tmp != head);
        printf ("\n");
    }
    void josephusGame (int M) 
    {
        printf ("JosephusGame delete order: size(%d) \t", size);
        Node<T> *node = head;
        while (size > 1)
        {
            for (int i = 0; i < M; ++i)
            {
                node = node->next;
            }
            Node<T> *del = node;
            node->prev->next = node->next;
            node->next->prev = node->prev;
            node = node->next;
            if (del == head) {
                head->next->prev = head->prev;
                head->prev->next = head->next;
                head = head->next;
            }
            printf ("%d\t", del->data);
            delete del;
            --size;
        }
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
    cl.josephusGame(M);
    cl.print_by_next();
    cl.print_by_prev();
    return 0;
}