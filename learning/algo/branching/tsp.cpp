/*travesal salesman problem*/
#include <iostream>
#include <vector>

using namespace std;

int BEST = INT_MAX;
vector<int> best_resolution;
int SIZE = 4;

int arr[4][4] = {
    0, 20, 35, 42,
    20, 0, 34, 30,
    35, 34, 0, 12,
    42, 30, 12, 0
};
// 1 2 4 3 1 -> 97

int check[] = {0, 0, 0, 0};

void print (vector<int> vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        printf ("%d\t", *it);
    }
    printf ("\n");
}

void tsp (int i, int sum, int check[], vector<int> & result) {
    for (int j = 0; j < SIZE; ++j){
        if (check[j] == 0 && i != j) {
            result.push_back (j + 1);
            check[j] = 1;
        } else {
            continue;
        }
        if (result.size() > 1)
            sum += arr[result[result.size() - 2] - 1][result[result.size() - 1] - 1];
        if (i == SIZE - 1) {
            sum += arr[result[result.size() - 1] - 1][result[0] - 1];
            result.push_back (result[0]);
            if (sum < BEST){
                best_resolution = result;
                BEST = sum;
            } else {
                
            }
            sum -= arr[result[result.size() - 1] - 1][result[0] - 1];
            result.pop_back();
        } else {
            tsp (i + 1, sum, check, result);
        }
        if (result.size() > 1)
            sum -= arr[result[result.size() - 2] - 1][result[result.size() - 1] - 1];
        check[j] = 0;
        result.pop_back();
    }
}

int main (int argc, char* argv[]) {
    int check[] = {0, 0, 0, 0};
    vector<int> result;
    int sum = 0;
    tsp (0, sum, check, result);
    print (best_resolution);
    printf ("sum = %d\n", BEST);
}