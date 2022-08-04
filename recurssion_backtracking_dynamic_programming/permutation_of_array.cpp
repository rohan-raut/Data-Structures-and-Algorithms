/*
*   author: rohanraut
*   created on: 05.04.2022 09:39:25
*/

#include <bits/stdc++.h>

using namespace std;

void display(vector<int> &v){
    for(int i=0; i<v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}


void permutation(int i, vector<int> &v){
    if(i==v.size()-1){
        display(v);
    }

    for(int j=i; j<v.size(); j++){
        swap(v[i],v[j]);
        permutation(i+1,v);
        swap(v[i],v[j]);   // Backtrack
    }
}

int main()
{
    vector<int> v = {1,2,3,4};
    permutation(0,v);


    return 0;
}


// Time Complexity - O(n!)
// Space Complexity - O(n)