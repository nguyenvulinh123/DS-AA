/* atm withdrawal */
#include <iostream>
#include <vector>

using namespace std;

int arr[] = {200, 10, 20, 20, 50, 50, 50, 50, 100, 100};
int SIZE = 10;
int COUNT_MIN =  INT_MAX;
vector<int> best_solution;

void print (vector<int> vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        printf ("%d\t", *it);
    }
    printf ("\n");
}

void ATM (int total, int count, vector<int> & result, int check[]) {
    for (int i = 0; i < SIZE; ++i) {
        if (check[i] == 0) {
                check[i] = 1;
                result.push_back (arr[i]);
                total -= arr[i];
                if (total == 0) {
                    if (count < COUNT_MIN) {
                        COUNT_MIN = count;
                        best_solution = result;
                    }
                } else if (total > 0) {
                    ATM (total, count + 1, result, check);
                } else {
                    // do nothing
                }
                check[i] = 0;
                total += arr[i];
                result.pop_back();
        }
    }
}

int main() {
    vector<int> result;
    int check[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    ATM (390, 0, result, check);
    print (best_solution);
}