/*
    longest common subsequence
*/
#include <iostream>
#include <algorithm>

using namespace std;

int lcs (char *a, char *b, int SIZE_A, int SIZE_B) {
    int arr[SIZE_A][SIZE_B];
    for (int i = 0; i < SIZE_A; ++i) {
        for (int j = 0; j < SIZE_B; ++j) {
            if ((i == 0) || (j == 0)) {
                arr[i][j] = 0;
            }
            else {
                if (a[i - 1] == b[j-1]) {
                    arr[i][j] = max (arr[i - 1][j], max (arr[i][j - 1], arr[i - 1][j - 1]));
                } else {
                    arr[i][j] = max (arr[i - 1][j], max (arr[i][j - 1], arr[i - 1][j - 1] + 1));
                }
            }
        }
    }
    return arr[SIZE_A - 1][SIZE_B - 1];
}

int main (int argc, char * argv[]) {
    char *a = "AGGTAB";
    char *b = "GXTXAYB";
    printf ("longest common subsequence : %d\n", lcs (a, b, 6, 6));
    return 0;
}