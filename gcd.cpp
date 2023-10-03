#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <chrono>

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
    a = abs(a);
    b = abs(b);

    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = min(az, bz);
    b >>= bz;

    while (a != 0) {
        a >>= __builtin_ctz(a);
        b = min(a, b);
        a = fabs(b - a);
    }

    return b << shift;
}


int pusk(int t)
{
    auto tStart1 = chrono::steady_clock::now();
    for (int i = 0; i < t; ++i) {
        //srand((int)time(NULL));
        int a = (rand() * 100 + rand()) % 2000000 - 1000000;
        int b = (rand() * 100 + rand()) % 2000000 - 1000000;
        normal_gcd(a, b);
    }

    auto tEnd1 = chrono::steady_clock::now();
    auto time_algo1 = chrono::duration_cast<chrono::milliseconds>(tEnd1 - tStart1).count();

    auto tStart2 = chrono::steady_clock::now();
    for (int i = 0; i < t; ++i) {
        //srand((int)time(NULL));
        int a = (rand() * 100 + rand()) % 2000000 - 1000000;
        int b = (rand() * 100 + rand()) % 2000000 - 1000000;
        binary_gcd(a, b);
    }

    auto tEnd2 = chrono::steady_clock::now();
    auto time_algo2 = chrono::duration_cast<chrono::milliseconds>(tEnd2 - tStart2).count();

    cout << "Quantity of tests is lower than " << t << ":\n";
    cout << "Slow algo: " << time_algo1 << "ms\n";
    cout << "Fast algo: " << time_algo2 << "ms\n";
    return(0);

}

int main()
{
    for (int t = 1; t <= 10000000; t*=10)
        pusk(t);

}
