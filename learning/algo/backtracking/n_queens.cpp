#include <iostream>
#include <vector>

using namespace std;

#define SIZE 8

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};

void print (vector<int> vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        printf ("%d \t", *it);
    }
    printf ("\n");
}

void n_queens (int i, vector<int> & result) {
    for (int j = 0; j < SIZE; ++j) {
        bool isOk = true;
        for (int k = 0; k < i; ++k) {
            if ((j == result[k] - 1)
                || (j - i == result[k] - 1 - k)
                || (j + i == result[k] - 1+ k)
            ) {
                isOk = false;
            }
        }
        if (isOk) {
            result.push_back(arr[j]);
        } else {
            continue;
        }
        if (i == SIZE - 1) {
            print (result);
        } else {
            n_queens (i + 1, result);
        }
        result.pop_back();
    }
}

int main (int argc, char * argv[]) {
    vector<int> result;
    n_queens (0, result);
    return 0;
}

