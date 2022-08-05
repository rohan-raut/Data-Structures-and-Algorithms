/*
    Time complexity: O(log(log(n))) almost linear
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1000;
vector<int> prime(N+1,1);
void sieve(){
    prime[1]=0;
    prime[0]=0;
    for(int i=2; i<=N; i++){
        if(!prime[i]) continue;
        for(int j=i*i; j<=N; j+=i){
            prime[j]=0;
        }
    }
}

int main()
{
    sieve();
    for(int i=0; i<=10; i++){
        cout<<prime[i]<<" ";
    }
    cout<<endl;
    
    return 0;
}