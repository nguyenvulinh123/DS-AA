#include <iostream>
#include <list>

template <typename T>
using LIST = std::list<T>;

template <typename T>
LIST<T> intersection_two_shorted_lists (const LIST<T> &l1, const LIST<T> &l2)
{
    LIST<T> tmp;
    auto it1 = l1.begin();
    auto it2 = l2.begin();
    while (it1 != l1.end() && it2 != l2.end())
    {
        if (*it1 == *it2){
            tmp.push_back (*it1);
            ++it1;
            ++it2;
        } else if (*it1 < *it2) {
            ++it1;
        } else {
            ++it2;
        }
    }
    return tmp;
}

template <typename T>
void print (const LIST<T> l1)
{
    printf ("intersection two shorted list: \t");
    for (auto it = l1.begin(); it != l1.end(); ++it)
    {
        printf ("%d\t", *it);
    }
    printf ("\n");
}

int main(int argc, char* argv[])
{
    LIST<int> l1 {1, 3, 5, 6};
    LIST<int> l2 {2, 3, 4, 6};
    LIST<int> tmp = intersection_two_shorted_lists (l1, l2);
    print(tmp);
}

