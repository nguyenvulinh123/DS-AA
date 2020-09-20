#include <iostream>

// selection sort
void sort (int arr[], int N)
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = i; j < N; ++j)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

int find_Kth_Element (int arr[], int N, int k)
{
    if (k > N - 1)
        return -1;
    else {
        sort (arr, N);
        return N - k;
    }
}

int main(int argc, char* argv[])
{
    int arr[] {3, 2, 1, 9, 8, 6, 5};
    int i = find_Kth_Element(arr, sizeof(arr)/sizeof(int), 4);
    printf ("k th element: %d\n", arr[i]);
    return 0;   
}