#include <bits/stdc++.h>
using namespace std;

// The graph should be represented using adjancency matrix

vector<vector<int>> floyd(vector<vector<int>> &graph){
    int n = graph.size();
    vector<vector<int>> dist(n+1, vector<int> (n+1, 1e7));

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return dist;
}

int main()
{

    return 0;
}