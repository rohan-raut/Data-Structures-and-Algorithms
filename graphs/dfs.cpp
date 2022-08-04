/*
*   author: rohanraut
*   created on: 07.09.2021 22:58:53
*/

// Reference Link:
// 1. https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
// 2. https://www.youtube.com/watch?v=vf-cxgUXcMk&list=PLm77mruelczpPDzLgp4UefbQRT4-cyJsW&index=2

#include <bits/stdc++.h>

using namespace std;

int v = 9;
vector<vector<int>> a(v);
vector<bool> visited(v, false);

void createEdge(int u, int v)
{
    a[u].push_back(v);
    // a[v].push_back(u);
}

void dfs(vector<vector<int>> &a, vector<bool> &visited, int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int i = 0; i < a[u].size(); i++)
    {
        if (visited[a[u][i]] == false)
        {
            dfs(a, visited, a[u][i]);
        }
    }
}

int main()
{

    // createEdge(0, 1);
    // createEdge(0, 2);
    // createEdge(1, 2);
    // createEdge(2, 0);
    // createEdge(2, 3);
    // createEdge(3, 3);

    createEdge(0, 1);
    createEdge(0, 9);
    createEdge(1, 2);
    createEdge(2, 0);
    createEdge(2, 3);
    createEdge(9, 3);

    // cout << "hello";
    dfs(a,visited,0);

    return 0;
}