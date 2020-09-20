#include <iostream>

void find_K_th_element(int arr[], int N, int k)
{
    if (k >= N)
    {
        printf ("item not found!\n");
        return;
    } else {
        for (int i = 1; i < N; ++i)
        {
            int temp = arr[i];
            int j = i - 1;
            while (j >= 0 && temp < arr[j])
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j+1] = temp;
        }
        printf ("Kth items: %d\n", arr[k]);
    }

}

int main(int argc, char* argv[])
{
    int arr[] {3, 2, 1, 9, 8, 7, 4, 5};
    find_K_th_element (arr, sizeof(arr)/sizeof(int), sizeof(arr)/sizeof(int)/2);
}