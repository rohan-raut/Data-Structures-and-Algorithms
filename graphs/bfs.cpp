/*
*   author: rohanraut
*   created on: 07.09.2021 23:18:58
*/

// Reference link:
// 1. https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// 2. https://www.youtube.com/watch?v=vf-cxgUXcMk&list=PLm77mruelczpPDzLgp4UefbQRT4-cyJsW&index=2

#include <bits/stdc++.h>

using namespace std;

void createEdge(vector<vector<int>> &a, int u, int v){
    a[u].push_back(v);
}

void bfs(vector<vector<int>> &a, vector<bool> &visited, int u){
    queue<int> q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        u=q.front();
        cout<<u<<" ";
        q.pop();
        for(int i=0; i<a[u].size(); i++){
            if(visited[a[u][i]]==false){
                q.push(a[u][i]);
                visited[a[u][i]]=true;
            }
        }
    }

}


int main()
{
    int v=4;
    vector<vector<int>> a(v);
    vector<bool> visited(v,false);

    createEdge(a,0,1);    
    createEdge(a,0,2);
    createEdge(a,1,2);
    createEdge(a,2,0);
    createEdge(a,2,3);
    createEdge(a,3,3);    

    bfs(a,visited,2);

    return 0;
}