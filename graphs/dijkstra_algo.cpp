/*
*   author: rohanraut
*   created on: 28.08.2021 12:24:46
*/

// Reference Link:
// 1. https://www.youtube.com/watch?v=smHnz2RHJBY&list=PLm77mruelczpPDzLgp4UefbQRT4-cyJsW&index=12
// 2. https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/

// First do Prim's algorithm and its implemention

#include <bits/stdc++.h>

using namespace std;

int V=9;

int minKey(vector<int> &key, vector<bool> &mstSet){
    int min=INT_MAX, min_index;
    for(int i=0; i<V; i++){
        if(mstSet[i]==false && key[i]<=min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void printpath(vector<int> &parent, vector<int> &key){
    cout<<"Path:\t Distance\n";
    for(int i=0; i<V; i++){
        cout<<i<<"\t"<<key[i]<<endl;
    }
}

void dijkstra(vector<vector<int>> &graph, int src){
    vector<int> parent(V);
    vector<bool> mstSet(V, false);
    vector<int> key(V,INT_MAX);

    parent[0]=-1;
    key[0]=0;

    for(int i=0; i<V; i++){
        int u= minKey(key, mstSet);
        mstSet[u]=true;

        for(int v=0; v<V; v++){
            if(mstSet[v]==false && graph[u][v]!=0 && (graph[u][v]+key[u])<key[v]){
                parent[v]=u;
                key[v]=key[u]+graph[u][v];
            }
        }
    }

    printpath(parent, key);
}

int main()
{
    vector<vector<int>> graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0}, {4, 0, 8, 0, 0, 0, 0, 11, 0}, {0, 8, 0, 7, 0, 4, 0, 0, 2}, {0, 0, 7, 0, 9, 14, 0, 0, 0}, {0, 0, 0, 9, 0, 10, 0, 0, 0}, {0, 0, 4, 14, 10, 0, 2, 0, 0}, {0, 0, 0, 0, 0, 2, 0, 1, 6}, {8, 11, 0, 0, 0, 0, 1, 0, 7}, {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    dijkstra(graph, 0);
    return 0;
}