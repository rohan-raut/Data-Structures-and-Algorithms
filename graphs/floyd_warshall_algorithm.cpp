/*
*   author: rohanraut
*   created on: 28.08.2021 20:53:52
*/

// Reference Link:
// 1. youtube.com/watch?v=Gc4mWrmJBsw
// 2. https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

#include <bits/stdc++.h>

using namespace std;

int V=4;

void printGraph(vector<vector<int>> &graph){
    for(int i=0; i<V; i++){
        for(int j=0; j<V; j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
}

void algo(vector<vector<int>> graph){
    for(int k=0; k<V; k++){
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(i==j){
                    graph[i][j]=0;
                }
                if(i==k || j==k){
                    continue;
                }
                if(((graph[i][k]+graph[k][j])<graph[i][j]) && graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX){
                    graph[i][j]= (graph[i][k]+graph[k][j]);
                }
            }
        }
    }

    printGraph(graph);
}

int main()
{
    vector<vector<int>> graph = {{0, 5, INT_MAX, 10}, 
                                {INT_MAX, 0, 3, INT_MAX}, 
                                {INT_MAX, INT_MAX, 0, 1}, 
                                {INT_MAX, INT_MAX, INT_MAX, 0}};

    algo(graph);
    return 0;
}