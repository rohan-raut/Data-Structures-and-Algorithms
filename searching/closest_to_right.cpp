/*
*   author: rohanraut
*   created on: 08.08.2022 20:02:28
*/

#include <bits/stdc++.h>
using namespace std;

int upper_bound_(vector<int> &a, int num){
    int l=0, r=a.size()-1;
    while(r-l>1){
        int mid=(l+r)/2;
        if(a[mid]<num){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    int ans=a.size()+1;
    if(a[r]>=num){
        ans=r+1;
    }
    if(a[l]>=num){
        ans=l+1;
    }
    return ans;
}

int main()
{

    return 0;
}