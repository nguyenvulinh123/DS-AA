#include <iostream>
#include <list>

void printLost(const std::list<int> &l, const std::list<int> & p)
{
    printf ("print lost: \t");
    int tmp = 0;
    for (std::list<int>::const_iterator it = p.begin(); it != p.end(); ++it)
    {
        std::list<int>::const_iterator it_l = l.begin();
        int delta = *it - tmp;
        tmp = *it;
        while (delta > 0)
        {
            ++it_l;
            delta--;
        }
        printf ("%d\t", *it);
    }
    printf ("\n");
}

int main (int argc, char* argv[])
{
    std::list<int> l {1, 2, 3 ,4, 5, 6, 7, 8, 9};
    std::list<int> p {1, 3, 4, 7};
    printLost(l, p);
    return 0;
}

// complexity: O(N) = 1*d1 + 1*d2 + 1*d3 ... + 1*dn = 1*(d1 + d2 + ... dn) = 1 *Size(L)
