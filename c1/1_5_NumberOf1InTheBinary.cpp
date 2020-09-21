#include <iostream>

int numbersOf1InBinary(int n)
{
    if (n == 0 || n== 1)
    {
        return n;
    }
    else {
        return (n%2 == 0) ? numbersOf1InBinary(n/2) : numbersOf1InBinary(n/2) + 1; 
    }
}

int main(int argc, char* argv[])
{
    int i = numbersOf1InBinary(63);
    printf ("numbersOf1InBinary = %d\n", i);
}
