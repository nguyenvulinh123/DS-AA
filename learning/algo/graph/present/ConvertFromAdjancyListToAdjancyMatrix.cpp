// ConvertFromAdjancyListToAdjancyMatrix
#include <iostream>
using namespace std;

void ConvertFromAdjancyListToAdjancyMatrix (int list[], int size_list, int head[], int size_head) {
    int arr[size_head -1][size_head - 1];
    memset (arr, 0, sizeof (arr));
    for (int i = 1; i < size_head; ++i) {
        for (int j = head[i - 1]; j < head[i]; ++j) {
            arr[i - 1][list[j] - 1] = 1;
        }
    }

    for (int i = 0; i < size_head - 1; ++i) {
        for (int j = 0; j < size_head - 1; ++j) {
            printf ("%d\t", arr[i][j]);
        }
        printf ("\n");
    }

}

int main (int argc, char * argv[]) {
    int list[] = {2, 3, 1, 3, 4, 5, 1, 2, 5, 2, 5, 2, 3, 4}; //size: 14
    int head[] = {0, 2, 6, 8, 11, 14}; // size: 5;
    ConvertFromAdjancyListToAdjancyMatrix (list, 14, head, 6);
}