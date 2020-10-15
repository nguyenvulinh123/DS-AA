#include <iostream>
#include <list>

typedef std::list<int> LIST;

LIST adjoint_two_shorted_lists (const LIST &l1, const LIST &l2)
{
    LIST::const_iterator it1 = l1.begin();
    LIST::const_iterator it2 = l2.begin();
    LIST tmp;
    while (it1 != l1.end() && it2 != l2.end())
    {
        if (*it1 == *it2)
        {
            tmp.push_back (*it1);
            ++it1;
            ++it2;
        } else if (*it1 > *it2) {
             tmp.push_back(*it2);
             ++it2;   
        } else {
            tmp.push_back (*it1);
            ++it1;
        }
    }
    return tmp;
}
void print (const LIST &l)
{
    printf ("list: \t");
    for (auto it = std::begin (l); it != std::end(l); ++it)
    {
        printf ("%d\t", *it);
    }
    printf ("\n");
}

int main(int arg, char* argv[])
{
    LIST l1 {1, 3, 5, 7};
    LIST l2 {2, 3, 5, 6};
    LIST tmp = adjoint_two_shorted_lists(l1, l2);
    print (tmp);
}