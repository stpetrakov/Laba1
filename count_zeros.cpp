#include <iostream>
#include <cmath>
#include <ctime>
#include <stdlib.h>

typedef int T;
using namespace std;

int CountZeros (T x)
{
    size_t count = 0;

    while (x != 0) {
        count += !(x&1);
        x >>= 1;

    }

    return count;
}

int cnt5 (T x) {
    int t =floor(log(x) / log(2)) + 1;
    x = ( x & 0x55555555u ) + ( ( x >> 1 ) & 0x55555555u ) ;
    x = ( x & 0x33333333u ) + ( ( x >> 2 ) & 0x33333333u ) ;
    x = ( x & 0x0f0f0f0fu ) + ( ( x >> 4 ) & 0x0f0f0f0fu ) ;
    return t - x % 255u ;
}

int main()
{
    clock_t tStart1 = clock();
    for (int i = 0; i < 100000; ++i) {
        srand((int)time(NULL));
        int a = rand() % 100001;
        CountZeros (a);
    }

    clock_t end1 = clock();
    double time_algo1 = (double)(end1 - tStart1);

    clock_t tStart2 = clock();
    for (int i = 0; i < 100000; ++i) {
        srand((int)time(NULL));
        int a = rand() % 100001;
        cnt5 (a);
    }

    clock_t end2 = clock();
    double time_algo2 = (double)(end2 - tStart2);

    cout << time_algo1 << ' ' << time_algo2;
    return(0);
}
