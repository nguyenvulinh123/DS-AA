#include <iostream>
#include <string>

void swap (char &c1, char &c2)
{
    char temp = c1;
    c1 = c2;
    c2 = temp;
}

void permute(std::string s, int low, int height)
{
    if (low == height -1)
    {
        printf ("%s\t", s.c_str());
    }
    else {
        for (int i =low; i < height; ++i)
        {
            swap(s[i], s[low]);
            permute(s, low + 1, height);
            swap(s[i], s[low]);
        }
    }
}

int main(int argc, char* argv[])
{
    permute ("ABC", 0, 3);
    printf ("\n");
    permute ("ABCD", 0, 4);
}