/*
    finding the kth ancestor of a node in log(n) time.
*/

#include <bits/stdc++.h>

using namespace std;

int LOG = 31;

void dfs(vector<vector<int>> &tree, int node, vector<vector<int>> &ancestor, int parent){
    ancestor[node][0] = parent;
    for(int i=0; i<tree[node].size(); i++){
        dfs(tree, tree[node][i], ancestor, node);
    }
}


void fillAncestor(vector<vector<int>> &ancestor){
    for(int i=0; i<ancestor.size(); i++){
        for(int j=1; j<=LOG; j++){
            ancestor[i][j] = ancestor[ancestor[i][j-1]][j-1];
        }
    }
}


int KthAncestor(vector<vector<int>> &ancestor, int node, int k){
    // k = 5 -> 0101 means we need to take a jump of 2^0 and 2^2
    for(int i=0; i<=LOG; i++){
        if((1<<i) & k){
            node = ancestor[node][i];
        }
    }

    return node;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    freopen("error.txt","w",stderr);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n; // no. of nodes in a tree
    vector<vector<int>> tree;
    vector<vector<int>> ancestor(n, vector<int> (LOG, -1));
    // ancestor[i][j] -> 2^j th parent of node i

    // first fill all the parents of nodes, all ancestor[][0] using dfs
    int root = 1;
    dfs(tree, root, ancestor, -1);

    // Now fill all the ancestors who are power of 2
    fillAncestor(ancestor);

    // find any kth ancestor of any node now
    int par = KthAncestor(ancestor, 2, 5);
    
    
    return 0;
}