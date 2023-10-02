#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>

using namespace std;
int normal_gcd (int a, int b)
{
    if (b == 0)
        return a;
    else
        return normal_gcd(b, a % b);
}

int binary_gcd (int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;

    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = std::min(az, bz);
    b >>= bz;

    while (a != 0) {
        a >>= az;
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = min(a, b);
        a = fabs(diff);
    }

    return b << shift;
}


int main()
{

    clock_t tStart1 = clock();
    for (int i = 0; i < 1000000; ++i) {
        srand((int)time(NULL));
        int a = rand() % 100001;
        int b = rand() % 100001;
        normal_gcd(a, b);
    }

    clock_t end1 = clock();
    double time_algo1 = (double)(end1 - tStart1);

    clock_t tStart2 = clock();
    for (int i = 0; i < 1000000; ++i) {
        srand((int)time(NULL));
        int a = rand() % 100001;
        int b = rand() % 100001;
        binary_gcd(a, b);
    }

    clock_t end2 = clock();
    double time_algo2 = (double)(end2 - tStart2);

    cout << time_algo1 << ' ' << time_algo2;
    return(0);
}
