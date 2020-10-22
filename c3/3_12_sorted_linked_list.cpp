#include <iostream>
#include <initializer_list>

template<typename T>
struct Node{
    T data;
    Node * next;
    Node (T t) : data(t), next(nullptr) {
        next = nullptr;
    }
};
template <typename T>
class SortedList {
    public:
    SortedList () : _size(0), _head(nullptr) {
    }
    SortedList (std::initializer_list<T> l) :_size(0), _head(nullptr) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            insert (*it);
        }
    }
    ~SortedList () {
        Node <T> * del = _head;
        while (_head) {
            _head = _head->next;
            delete del;
            del = _head;
        }
    }
    void insert (T t) {
        _size++;
        Node<T> * node = new Node<T> (t);
        if (_head == nullptr){
            _head = node;
        } else if (_head->data > t) {
            node->next = _head;
            _head = node;
        } else {
            Node <T> * tmp = _head;
            while (tmp->next && tmp->next->data < t) {
                tmp = tmp->next;
            }
            node->next = tmp->next;
            tmp->next = node;
        }
    }
    unsigned size () {return _size;}
    void printf_list () {
        std::cout << "printf list: \t";
        Node <T> *tmp = _head;
        while (tmp) {
            std::cout << tmp->data << "\t";
            tmp = tmp->next;
        }
        std::cout << "\n";
    }
    private:
    unsigned int _size;
    Node<T> * _head;
};
// 1 3 5


int main(int argc, char* argv[]){
    SortedList<int> sort_list {1, 5, 4, 2, 3, 0};
    sort_list.printf_list();
}