/*
    Time Complexity: O(nlog(n))
    Space Complexity: O(log(n))*O(n)  -> log(n) for internal stack
*/

#include <bits/stdc++.h>
using namespace std;

int merge(vector<int> &a, int l, int mid, int r){
    vector<int> b(r-l+1);
    int i=l, j=mid+1, k=0;
    int inv = 0;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
            inv += (mid-i+1);
            j++;
        }
        k++;
    }

    while(i<=mid){
        b[k] = a[i];
        i++;
        k++;
    }
    while(j<=r){
        b[k] = a[j];
        j++;
        k++;
    }

    for(k=0; k<b.size(); k++){
        a[l+k] = b[k];
    }

    return inv;
}

int mergeSort(vector<int> &a, int l, int r){
    int inv = 0;
    if(l<r){
        int mid = (l+r)/2;
        inv += mergeSort(a,l,mid);
        inv += mergeSort(a,mid+1,r);
        inv += merge(a,l,mid,r);
    }
    return inv;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    int inv = mergeSort(a, 0, n-1);
    cout<<inv<<endl;

    
    
    return 0;
}