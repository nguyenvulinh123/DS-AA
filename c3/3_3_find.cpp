#include <iostream>
#include <vector>

template <typename Iterator, typename Object>
Iterator my_find (Iterator start, Iterator end, const Object &obj) {
    Iterator tmp = start;
    while (tmp != end)
    {
        if (*tmp == obj)
        {
            return tmp;
        } else {
            ++tmp;
        }
    }
    return end;
}

int main(int argc, char* argv[])
{
    std::vector<int> v {1, 2, 3, 9, 2, 5};
    std::vector<int>::iterator it = my_find <std::vector<int>::iterator, int> (v.begin(), v.end(), 3);
    printf ("found: %d\n", *it);
}