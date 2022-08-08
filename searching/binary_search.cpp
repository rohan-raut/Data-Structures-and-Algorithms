#include <bits/stdc++.h>

using namespace std;

int binary_search(vector<int> &arr, int num){
    int l=0, r=arr.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==num){
            return mid;
        }
        else if(num>arr[mid]){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int main()
{
    vector<int> arr = {2,4,5,77,88,100,102};

    cout<<binary_search(arr,102)<<endl;
    
    return 0;
}