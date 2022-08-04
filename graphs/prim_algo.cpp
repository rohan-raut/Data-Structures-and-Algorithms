/*
*   author: rohanraut
*   created on: 27.08.2021 19:57:56
*/

// Reference Link:
// 1. https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
// 2. https://www.youtube.com/watch?v=ZtZaR7EcI5Y&t=458s

#include <bits/stdc++.h>

using namespace std;

int minKey(vector<int> &key, vector<bool> &mstSet){
    int min=INT_MAX, min_index;
    for(int i=0; i<key.size(); i++){
        if(key[i]<min && mstSet[i]==false){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void printMST(vector<int> &parent, vector<int> &key){
    int weight=0;
    for(int i=0; i<key.size(); i++){
        weight+=key[i];
    }
    cout<<"Weight of MST: "<<weight<<endl;
    for(int i=0; i<parent.size(); i++){
        cout<<i<<"->"<<parent[i]<<endl;
    }
}

void prim(vector<vector<int>> &graph){
    vector<int> parent(5); //vector to store the constructed MST, node i is connected to node parent[i]
    vector<bool> mstSet(5, false); // vector to store weather the vertex is included in MST or not
    vector<int> key(5, INT_MAX); // vector to store minimum adjacent edge weight for a particular vertex

    key[0]=0;
    parent[0]=-1;

    for(int i=0; i<5; i++){
        int u= minKey(key, mstSet);
        mstSet[u]=true;

        for(int v=0; v<5; v++){
            if(graph[u][v]!=0 && mstSet[v]==false && graph[u][v]<key[v]){
                parent[v]=u;     //vertex v is connected to vertex u
                key[v]=graph[u][v];   //we just store the weights of adjacent vertices, the vertices is still not included in MST
            }
        }

        printMST(parent, key);

    }

}

int main()
{
    int V = 5; //no. of vertices
    vector<vector<int>> graph = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};

    prim(graph);

    
    return 0;
}