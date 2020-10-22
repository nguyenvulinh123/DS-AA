#include <iostream>
#include <initializer_list>

using std::cout;
template<typename T>
struct Node {
    Node (T t) : data (t) {
        next = nullptr;
    }
    T data;
    Node * next;
};

template <typename T>
class List {
    public:
    explicit List () {
        _head = nullptr;
    }
    List (std::initializer_list<T> list) {
        _head = nullptr;
        for (auto it = list.begin(); it != list.end(); ++it) {
            insert_back (*it);
        }
    }
    void insert_front (T t){
        Node <T> * node = new Node<T> (t);
        if (_head == nullptr) {
            _head = node;
        } else {
            node->next = _head;
            _head = node;
        }
    }
    void insert_back (T t) {
        Node <T> * node = new Node<T> (t);
        if (_head == nullptr) {
            _head = node;
        } else {
            Node<T> * tmp = _head;
            while (tmp->next) {
                tmp = tmp->next;
            }
            tmp->next = node;
        }

    }
    unsigned size () {
        unsigned result = 0;
        Node<T> * tmp = _head;
        while (tmp) {
            result++;
            tmp = tmp->next;
        }
        return result;
    }
    void printf_list () {
        cout << "print_list: \t";
        Node<T> * tmp = _head;
        while (tmp) {
            cout << tmp->data << "\t";
            tmp = tmp->next;
        }
    }
    void add (T t) {
        if (_head == nullptr){
            insert_front(t);
        } else {
            Node<T> * tmp = _head;
            while (tmp->next) {
                if (tmp->data == t) {
                    cout << "t[" << t << "] : already exist!!!\n";
                    return;
                } else {
                    tmp = tmp->next;
                }
            }
            Node <T> * node = new Node<T> (t);
            tmp->next = node;
        }
    }
    void remove(T t) {
        Node <T> * tmp = _head;
        if (_head == nullptr){
            return;
        } else if (_head->data == t){
            Node<T> * del = _head;
            tmp->next = tmp->next->next;
            _head = tmp->next;
            delete del;
        } else {
            while (tmp->next)
            {
                if (tmp->next->data == t)
                {
                    Node<T> * del = tmp->next;
                    tmp->next = tmp->next->next;
                    delete del;
                }
                tmp = tmp->next;
            }
        }
    }
    private:
    Node<T> * _head;
};

int main (int argc, char* argv[]) {
    List <int> list {1, 2, 3, 4, 5};
    list.add(1);
    list.add(-1);
    list.remove(2);
    list.remove(3);
    list.printf_list();
    return 0;
}