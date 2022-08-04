/*
*   author: rohanraut
*   created on: 05.04.2022 09:49:02
*/

#include <bits/stdc++.h>

using namespace std;


void permutation(int i, string s){
    if(i==s.size()-1){
        cout<<s<<endl;
    }

    for(int j=i; j<s.size(); j++){
        swap(s[i],s[j]);
        permutation(i+1,s);
        swap(s[i],s[j]);
    }
}


int main()
{
    string s="rohan";
    permutation(0,s);

    return 0;
}


// Time Complexity - O(n!)
// Space Complexity - O(n)