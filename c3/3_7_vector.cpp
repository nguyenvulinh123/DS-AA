#include <iostream>
#include <algorithm>

using std::cout;
#define CAPACITY 10
template <typename Object>
class Vec {
    public:
    explicit Vec (int in = 0) : size (in), capacity (CAPACITY) {
        objs = new Object[size];
    }
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
    private:
    Object * objs;
    unsigned size;
    unsigned capacity;
};

int main(int argc, char* argv[])
{
    Vec<int> v(10);
}