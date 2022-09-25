#include <bits/stdc++.h>
using namespace std;


int N = 100005;
vector<int> SPF(N, 0);

// Time Complexity: O(nloglogn)
// Space Complexity: O(n)
void findSPF(){
    SPF[1] = 1;

    for(int i=2; i<N; i++){
        if(SPF[i] == 0){
            for(int j=i; j<N; j+=i){
                if(SPF[j] == 0){
                    SPF[j] = i;
                }
            }
        }
    }
}

// Time & Space Complexity: O(log n)
vector<int> getFactors(int n){
    vector<int> factors;

    if(n == 1){
        return {1};
    }

    while(n != 1){
        factors.push_back(SPF[n]);
        n = n/SPF[n];
    }

    return factors;
}


int main()
{
    findSPF();
    vector<int> fact = getFactors(1);

    for(auto x: fact) cout<<x<<" ";
    cout<<endl;
    
    
    return 0;
}