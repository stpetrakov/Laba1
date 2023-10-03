#include <iostream>
#include <cmath>
#include <chrono>
#include <stdlib.h>

typedef double T;
using namespace std;

int64_t DoubleToInt64Bits(double value)
{
    return *(int64_t*)(&value);
}

int CountZeros_bad (T y)
{
    size_t count = 0;
    int64_t x = DoubleToInt64Bits (y);

    while (x != 0) {
        count += !(x&1);
        x >>= 1;

    }

    return count;
}

int CountZeros_good (T y) {
    int64_t x = DoubleToInt64Bits (y);
    int t = 0, x1 = x;
    for(t = 0; x1 != 0; t++){
        x1 = x1>>1;
    }
    x = ( x & 0x55555555u ) + ( ( x >> 1 ) & 0x55555555u ) ;
    x = ( x & 0x33333333u ) + ( ( x >> 2 ) & 0x33333333u ) ;
    x = ( x & 0x0f0f0f0fu ) + ( ( x >> 4 ) & 0x0f0f0f0fu ) ;
    return t - x % 255u;
}

int pusk (int t)
{
    auto tStart1 = chrono::steady_clock::now();
    for (int i = 0; i < t; ++i) {
        int a = (rand() * 100 + rand()) % 1000000;
        CountZeros_bad (a);
    }

    auto tEnd1 = chrono::steady_clock::now();
    auto time_algo1 = chrono::duration_cast<chrono::milliseconds>(tEnd1 - tStart1).count();

    auto tStart2 = chrono::steady_clock::now();
    for (int i = 0; i < t; ++i) {
        int a = (rand() * 100 + rand()) % 1000000;
        CountZeros_good (a);
    }

    auto tEnd2 = chrono::steady_clock::now();
    auto time_algo2 = chrono::duration_cast<chrono::milliseconds>(tEnd2 - tStart2).count();

    cout << "Quantity of tests is " << t << ":\n";
    cout << "Slow algo: " << time_algo1 << "ms\n";
    cout << "Fast algo: " << time_algo2 << "ms\n";
    return(0);
}

int main()
{
    for (int t = 1; t <= 100000000; t*=10)
        pusk(t);
}
