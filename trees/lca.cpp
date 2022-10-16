/*
    finding lowest common ancestor using binary lifting.
*/

#include <bits/stdc++.h>

using namespace std;

#define N 100000

int LOG = 31;
int depth[N];

void dfs(vector<vector<int>> &tree, int node, vector<vector<int>> &ancestor, int parent){
    ancestor[node][0] = parent;

    if(parent != -1){
        depth[node] = depth[parent] + 1;
    }
    
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


int lca(vector<vector<int>> &tree, vector<vector<int>> &ancestor, int a, int b){
    // consider a is always deapest node
    if(depth[a] < depth[b]){
        swap(a, b);
    }

    // make both nodes at same level
    int k = depth[a] - depth[b];
    a = KthAncestor(ancestor, a, k);

    // this is corner case where a and b becomes equal
    if(a == b){
        return a;
    }

    // get to the closest level of lowest common ancestor, start making higher jumbs in powers of 2
    for(int i=LOG; i>=0; i--){
        if(ancestor[a][i] != ancestor[b][i]){
            a = ancestor[a][i];
            b = ancestor[b][i];
        }
    }

    return ancestor[a][0];

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
    memset(depth, 0, sizeof(depth));
    dfs(tree, root, ancestor, -1);

    // Now fill all the ancestors who are power of 2
    fillAncestor(ancestor);

    // find any kth ancestor of any node now
    int par = KthAncestor(ancestor, 2, 5);
    
    
    return 0;
}