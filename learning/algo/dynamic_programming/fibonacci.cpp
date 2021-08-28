/*
    Fibonaaci
*/
#include <iostream>

using namespace std;

int fibonacci (int i) {
    if (i == 0 || i == 1) {
        return i;
    } else {
        return fibonacci (i -2) + fibonacci (i - 1);
    }
}

int fibonacci_dynamic1 (int i) {
    int arr[i+1];
    for (int j = 0; j <= i; ++j) {
        if (j == 0 || j == 1) {
            arr[j] = j;
        } else {
            arr[j] = arr[j - 1] + arr[j - 2];
        }
    }
    return arr[i];
}

int fibonacci_dynamic2 (int i) {
    int first, second = 0;
    for (int j = 0; j < i; ++j) {
        if (j == 0 || j == 1) {
            first = 0;
            second = 1;
        } else {
            int tmp = second;
            second = first + second;
            first = tmp;
        }
    }
    return first + second;
}

int main (int argc, char * argv[]) {
    int a;
    cout << "Enter a: ";  cin >> a;
    printf ("Fibonacci (%d) = %d\n", a, fibonacci_dynamic2 (a));
    return 0;
}