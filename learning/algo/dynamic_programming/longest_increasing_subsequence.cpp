/*
    Longest Increasing Subsequence
*/
#include <iostream>

using namespace std;

int arr[] = {9, 1, 2, 3, 4, 10, 5, 6, 7, 8};
const int SIZE = 10;

void printArr (int arr[], int SIZE) {
    for (int i = 0; i < SIZE; ++i) {
        printf ("%d\t", arr[i]);
    }
    printf ("\n");
}

int LSQ (int arr[] , int SIZE) {
    int L[SIZE];
    int result = 0;
    for (int i = 0; i < SIZE; ++i) {
        L[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j])
                L[i] = max (L[i], L[j] + 1);
        }
        result = max (result, L[i]);
    }
    printArr (L, SIZE);
    return result;
};


int main (int argc, char * argv[]) {
    printf ("LSQ: %d\n", LSQ (arr, 10));
    return 0;
}