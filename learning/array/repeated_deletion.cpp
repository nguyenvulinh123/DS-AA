/*
    Implement repeated delition algorithm using tow pointer
*/

#include <iostream>

int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

void repeated_deletion (int arr[], int size) {
    int write = 0;
    for (int i = 0; i < size; ++i) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[write] = arr[i];
            write++;
        }
    }
}

void printf_arr(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        printf ("%d\t", arr[i]);
    }
    printf ("\n");
}

int main(int argc, char * argv[]) {
    repeated_deletion (arr, 10);
    printf_arr (arr, 5);
    return 0;
}