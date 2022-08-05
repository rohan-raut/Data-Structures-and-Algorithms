/*
    Time Complexity: O(log n) n=power
    1. https://cp-algorithms.com/algebra/binary-exp.html
*/

#include <bits/stdc++.h>
using namespace std;

// To find the power
long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}


// To find the power with modulo, here m should be a prime number
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main()
{
    cout<<binpow(3,4)<<endl;

    return 0;
}