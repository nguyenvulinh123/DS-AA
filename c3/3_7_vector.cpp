#include <iostream>
#include <initializer_list>
#include <algorithm>
#include <stdexcept>  

using std::cout;
#define CAPACITY 10
template <typename Object>
class Vec {
    public:
    explicit Vec (int in = 0) : size (in), capacity (CAPACITY) {
        objs = new Object[size];
    }
    Vec (std::initializer_list<Object> list) {
        size = list.size();
        capacity = size * 2;
        objs = new Object[capacity];
        auto it = list.begin();
        for (int i = 0; i < size; ++i) {
            objs[i] = *it;
            ++it;
        }
    }
    // delete constructor
    ~Vec () {
        delete [] objs;
    }
    // copy constructor
    Vec (const Vec & v) : size(v.size), capacity (v.capacity)
    {
        objs = new Object[capacity];
        for (int i = 0; i < size; ++i)
        {
            objs[i] = v.objs[i];
        }
    }
    // move constructor 
    Vec (Vec && rhs) : size (rhs.size), capacity (rhs.capacity), objs(rhs.objs) {
        rhs.size = 0;
        rhs.capacity = 0;
        rhs.objs = nullptr;
    }
    // assignment operator
    Vec& operator = (const Vec & rhs) {
        Vec copy = rhs;
        std::swap (*this, copy);
        return *this;
    }
    // move assignment operator
    Vec & operator = (Vec && rhs) {
        std::swap (size, rhs.size);
        std::swap (capacity, rhs.capacity);
        std::swap (objs, rhs.objs);
        return *this;
    }

    Object & operator[] (int index) {
        if (index < 0 || index >= size) {
            throw  std::out_of_range ("Index out of range");
        } else {
            return objs[index];
        }
    }
    const Object & operator[] (int index) const {
        if (index < 0 || index >= size) {
            throw  std::out_of_range ("Index out of range");
        } else {
            return objs[index];
        }
    }

    void print_self () {
        printf ("Vec: \t");
        for (int i = 0; i < size; ++i) {
            printf ("%d\t", objs[i]);
        }
        printf("\n");
    }

    private:
    Object * objs;
    unsigned size;
    unsigned capacity;
};

int main(int argc, char* argv[])
{
    Vec<int> v2{1, 2, 3, 4};
    v2.print_self();
    v2[10] = 2;
}