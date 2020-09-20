#include <iostream>

void printDigit(int digit)
{
    if (digit > 10)
    {
        printDigit(digit/10);
        printf ("%d", digit%10);
    } else {
        printf ("%d", digit);
    }
}

int main (int argc, char* argv[])
{
    printDigit(12349873);
    printf ("\n");
}