/*
    knapsack
*/
#include <iostream>
#include <algorithm>
using namespace std;

int value[] = {60, 100, 120};
int weight[] = {10, 20, 30};
const int W = 50;

int knapsack (int value[], int weight[], int size, int W) {
    int arr[size][W];
    int result = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= W; ++j) {
            if (i == 0 || j == 0) {
                arr[i][j] = 0;
            } else {
                if (weight[j] < W) 
                    arr[i][j] = max (arr[i - 1][j], arr[i - 1][W - weight[j]] + value[i]);
                else 
                    arr[i][j] = arr[i - 1][j];
            }
            result = max (result, arr[i][j]);
        }
    }
    return result;
}

int main (int argc, char * argv[]) {
    printf ("kanpsack = %d\n", knapsack (value, weight, 3, 50));
    return 0;
}