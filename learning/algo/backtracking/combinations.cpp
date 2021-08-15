#include <iostream>
#include <vector>

using namespace std;

int arr[] = {1, 2, 3, 4};
const int SIZE = 4;
const int k = 3;

void print (vector<int> vec) {
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        printf ("%d\t", *it);
    }
    printf ("\n");
}
void find_combinations (int i, vector<int> &result) {
    for (int j = i; j < SIZE; ++j)
    {
        if (result.back() >= arr[j])
            continue; 
        result.push_back (arr[j]);
        if (i == k - 1) {
            print(result);
        } else {
            find_combinations (i + 1, result);
        }
        result.pop_back();
    }
}

int main(int argc, char* argv[]) {
    vector<int> result;
    result.reserve(k);
    find_combinations (0, result);
    return 0;
}
