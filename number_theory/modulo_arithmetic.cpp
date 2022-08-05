/*
    Add: (a + b) % M = ((a % M) + (b % M)) % M
    Mul: (a * b) % M = ((a % M) * (b % M)) % M
    Sub: (a - b) % M = ((a % M) - (b % M) + M) % M
    Div: (a / b) % M = ((a % M) * (inverse(b) % M)) % M

    inverse(n) can be calculated by binary exponentiation
*/

#include <bits/stdc++.h>
using namespace std;

const int M = 1e9+7;

long long int binpow(long long int a, long long int b, long long int m) {
    a %= m;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

long long int mod_add(long long int a, long long int b){
    a = a % M;
    b = b % M;
    return ((((a + b) % M) + M) % M);
}

long long int mod_mul(long long int a, long long int b){
    a = a % M;
    b = b % M;
    return ((((a * b) % M) + M) % M);
}

long long int mod_sub(long long int a, long long int b){
    a = a % M;
    b = b % M;
    return ((((a - b) % M) + M) % M);
}

long long int mod_div(long long int a, long long int b){
    a = a % M;
    b = b % M;
    return ((a * binpow(b, M-2, M)) % M);
}

int main()
{
    
    return 0;
}