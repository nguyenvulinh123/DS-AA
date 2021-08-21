/*Caculate power(a, n)*/
#include <iostream>

using namespace std;

int power (int a, int n) {
    if (n == 1) {
        return a;
    } else {
        int temp = power (a, n/2);
        if (n % 2 == 0) 
            return temp * temp;
        else
            return a * temp * temp;
    }
}

int main (int argc, char* argv[]) {
    int a, n;
    std::cout << "a = ,n = ";
    std::cin >> a >> n;
    printf("power (%d, %d) = %d\n", a, n, power(a, n));
    return 0;
}