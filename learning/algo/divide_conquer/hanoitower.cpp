/*
Hanoi tower
*/
#include <iostream>
#include <string>
using namespace std;

void hanoi_tower (int n, string src, string tmp, string dest) {
    if (n == 1)
        printf ("Move from \"%s\" to \"%s\" \n", src.c_str(), dest.c_str());
    else {
        hanoi_tower (n - 1, src, dest, tmp);
        hanoi_tower (1, src, tmp, dest);
        hanoi_tower (n - 1, tmp, dest, src);
    }
}

int main(int argc, char* argv[]) {
    hanoi_tower (5, "A", "B", "C");
}