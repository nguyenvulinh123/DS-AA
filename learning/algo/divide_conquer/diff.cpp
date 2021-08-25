#include <iostream>
#include <algorithm>

using namespace std;

int arr[] = {4, 2, 5, 11, 1, 7};
int SIZE = 6;

void findDiff (int start, int end, int & Diff, int & MIN, int & MAX){
    if (end == start) {
        Diff = 0;
        MIN = arr[end];
        MAX = arr[end];
    } else {
        int mid = (start + end)/2;
        int MaxD1, MaxV1, MinV1, MaxD2, MaxV2, MinV2;
        findDiff (start, mid, MaxD1, MinV1, MaxV1);
        findDiff (mid + 1, end, MaxD2, MinV2, MaxV2);
        Diff = MaxV2 - MinV1;
        if (Diff < MaxD1) 
            Diff = MaxD1;
        if (Diff < MaxD2)
            Diff = MaxD2;
            
        if (MaxV2 < MaxV1) 
            MAX = MaxV1;
        else 
            MAX = MaxV2;
        if (MinV2 < MinV1)
            MIN = MinV2;
        else 
            MIN = MinV1;
    }
}

int main(int argc, char * argv[]) {
    int Diff, Max, Min;
    findDiff (0, 6, Diff, Min, Max);
    cout << Diff << endl;

    return 0;
}
/*
int arr[] = {4, 2, 5, 8, 1, 7}
*/