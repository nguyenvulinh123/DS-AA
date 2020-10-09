#include <iostream>
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node (T t): data (t) {
        next = nullptr;
        prev = nullptr;
    } 
};
template <typename T>
class DouleLinkList {
    public:
    DouleLinkList () : size(0)
    {
        head = nullptr;
        tail = nullptr;
    }
    void push_back (T t)
    {
        Node<T> * node = new Node<T> (t);
        size++;
        if (!head && ! tail)
        {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    void push_front (T t)
    {
        Node <T> *node = new Node<T> (t);
        if (!head && !tail)
        {
            head = tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }
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
            head->prev = tmp;
            head->next = tmp->next;
            tmp->next = head;
            tmp->prev = head->prev;
            head = tmp;

        } else {
            // // node -> N1 -> N2 ->
            // Node<T> * node = head;
            // while (start_index > 1)
            // {
            //     start_index--;
            //     node = node->next;
            // }
            // Node<T> * tmp = node->next;
            // // swap two adjacents, increase 2 - 1 for swap more than 2 adjacent elements
            // for (int i = 0; i < 2 - 1; ++i)
            // {
            //     tmp = tmp->next;
            //     tmp->next = tmp->prev;
            //     tmp->prev = tmp;
            //     tmp = tmp->prev;
            // }

            // node->next = tmp;
            // tmp->prev = node;
        }
    }
    void print ()
    {
        Node<T> * tmp = head;
        std::cout << "Print: \t"; 
        while (tmp) {
            std::cout << tmp->data << "\t";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }
    private:
    Node<T> * head;
    Node<T> * tail;
    unsigned size;
};

int main(int argc, char* argv[])
{
    DouleLinkList<int> dl;
    for (int i = 0; i < 5; ++i)
    {
        dl.push_back (i);
    }
    for (int i = 5; i < 9; ++i)
    {
        dl.push_front (i);
    }
    dl.swap_two_adjacent(2);
    dl.print();
}