/*
*   author: rohanraut
*   created on: 07.02.2023 13:00:24
*/

#include <bits/stdc++.h>

using namespace std;


class DSU{
    private:
    vector<int> parent, sz;

    public:
    DSU(int n){
        parent.resize(n+1);
        sz.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int find_parent(int n){
        if(parent[n] == n){
            return n;
        }
        return parent[n] = find_parent(parent[n]);
    }

    void union_(int a, int b){
        a = find_parent(a);
        b = find_parent(b);
        if(a != b){
            if(sz[a] < sz[b]){
                swap(a, b);
            }
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
};


int main()
{

    
    return 0;
}