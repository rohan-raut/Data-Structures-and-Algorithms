/*
    Counting divisors for each number can have a time complexity of O(n*sqrt(n))
    If we rather store the count of multiples the time complexity becomes O(nlon(n))
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> cnt_div(int n){
    vector<int> div(n+1,0);
    for(int i=1; i<=n; i++){
        for(int j=i; j<=n; j+=i){
            div[j]++;
        }
    }
    return div;
}


int main()
{

    int n;
    cin>>n;
    vector<int> div = cnt_div(n);
    for(auto x: div) cout<<x<<" ";
    cout<<endl;

    return 0;
}