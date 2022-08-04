#include <bits/stdc++.h>

using namespace std;

bool isBipartie(vector<vector<int>> &graph, vector<int> &color, int node, int curr){
    if(color[node]!=-1 && color[node]!=curr){
        return false;
    }
    if(color[node]!=-1 && color[node]==curr){
        return true;
    }
    color[node]=curr;
    for(int i=0; i<graph[node].size(); i++){
        if(isBipartie(graph,color,graph[node][i], curr^1)==false){
            return false;
        }
    }
    return true;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n);
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    vector<int> color(n,-1);
    for(int i=0; i<color.size(); i++){
        if(color[i]==-1){
            cout<<isBipartie(graph,color,i,0);
        }
    }

    return 0;
}