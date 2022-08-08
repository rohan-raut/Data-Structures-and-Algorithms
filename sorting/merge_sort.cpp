/*
    Time Complexity: O(nlog(n))
    Space Complexity: O(log(n))*O(n)  -> log(n) for internal stack
*/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &a, int l, int mid, int r){
    vector<int> b(r-l+1);
    int i=l, j=mid+1, k=0;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k] = a[i];
            i++;
        }
        else{
            b[k] = a[j];
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
}

void mergeSort(vector<int> &a, int l, int r){
    if(l<r){
        int mid = (l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    mergeSort(a, 0, n-1);

    for(auto x: a) cout<<x<<" ";
    cout<<endl;
    
    return 0;
}