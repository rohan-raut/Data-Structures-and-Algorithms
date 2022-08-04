/*
*   author: rohanraut
*   created on: 23.08.2021 20:44:40
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> parent(20);
vector<int> sz(20,1);

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]= find_set(parent[v]);
}

void union_set(int a, int b){
    a= find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]){
            swap(a,b);
        }
        parent[b]=a;
        sz[a]+=sz[b];
    }
}


int main()
{
    int e;
    cin>>e;
    vector<vector<int>> edge;
    vector<vector<int>> ans;
    for(int i=0; i<e; i++){
        int w,u,v;
        cin>>w>>u>>v;
        edge.push_back({w,u,v});
    }

    // making up the parent vector
    for(int i=0; i<parent.size(); i++){
        parent[i]=i;
    }

    sort(edge.begin(), edge.end());
    int weight=0;
    bool cycle=false;

    for(int i=0; i<e; i++){
        int w=edge[i][0];
        int u=edge[i][1];
        int v=edge[i][2];

        int x=find_set(u);
        int y=find_set(v);
        if(x==y){
            cycle=true;
        }
        if(cycle){
            cycle=false;
            continue;
        }
        else{
            weight+=w;
            ans.push_back({u,v,w});
            union_set(u,v);
        }
    }

    cout<<"weight: "<<weight<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }

    
    return 0;
}

// 14
// 4 0 1
// 11 1 7
// 8 1 2
// 8 0 7
// 7 2 3
// 2 2 8
// 4 2 5
// 9 3 4
// 14 3 5
// 10 4 5
// 2 5 6
// 1 6 7
// 6 6 8
// 7 7 8