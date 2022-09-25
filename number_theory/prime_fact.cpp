#include <bits/stdc++.h>
using namespace std;

/*
    This approach gives factors in O(log n) if the number is not prime, otherwise O(n)
*/

void primeFactors(int n){
    int i = 2;
    while(n > 1){
        if(n % i == 0){
            cout<<i<<" ";
            n = n/i;
        }
        else{
            i++;
        }
    }
}


int main()
{
    int n = 12;
    primeFactors(12);

    cout<<endl;

    n = 13;
    primeFactors(13);
    
    return 0;
}