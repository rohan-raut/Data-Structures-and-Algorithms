/*
If their is an edge between u and v then in the topological sort u should always come before v.
Reference Link: 
1) https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=12
2) https://www.youtube.com/watch?v=dis_c84ejhQ&list=PLm77mruelczpPDzLgp4UefbQRT4-cyJsW&index=9
*/

#include <bits/stdc++.h>

using namespace std;

void topological_sort_dfs(vector<vector<int>> &graph, vector<int> &visited, stack<int> &st, int node){
    visited[node]=1;
    for(int i=0; i<graph[node].size(); i++){
        if(visited[graph[node][i]]==0){
            topological_sort_dfs(graph, visited, st, graph[node][i]);
        }
    }
    st.push(node);
}

int main()
{
    int n=6, m=6;
    vector<vector<int>> graph = {{},{},{3},{1},{0,1},{0,2}};
    stack<int> st;
    vector<int> visited(6,0);

    for(int i=0; i<n; i++){
        if(visited[i]==0){
            topological_sort_dfs(graph, visited, st, i);
        }
    }

    for(int i=0; i<n; i++){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}