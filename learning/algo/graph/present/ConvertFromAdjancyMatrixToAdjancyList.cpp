#include <iostream>

using namespace std;

int arr[][5] = {
    {0, 1, 1, 0, 0},
    {1, 0, 1, 1, 1},
    {1, 1, 0, 0, 1},
    {0, 1, 0, 0, 1},
    {0, 1, 1, 1, 0}
    };


void ConverFromAdjancyMatrixToAdjancyList (int arr[][5], int size) {
    int list[size*(size -1)];
    int head[size + 1];
    int index_list = 0;
    int index_head = 1;
    head[0] = 0;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (arr[i][j] == 1) {
                list [index_list++] = j + 1;
            }
        }
        head[index_head++] = index_list;
    }
    printf ("list = \n");
    for (int i = 0; i < index_list; ++i) {
        printf ("%d\t", list[i]);
    }
    printf ("\nhead = \n");
    for (int i = 0; i < index_head; ++i) {
        printf ("%d\t", head[i]);
    }
}

int main (int argc, char* arggv[]) {
    ConverFromAdjancyMatrixToAdjancyList (arr, 5);
    return 0;
}