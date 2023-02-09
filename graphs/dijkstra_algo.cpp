#include <bits/stdc++.h>

using namespace std;

vector<int> dijkstras(vector<vector<pair<int,int>>> &graph, int src){
    int n = graph.size();
    vector<int> dist(n+1, 1e7);
    vector<int> par(n+1, -1); // to trase the path
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()){
        int d = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(int i=0; i<graph[node].size(); i++){
            if(dist[node] + graph[node][i].second < dist[graph[node][i].second]){
                dist[graph[node][i].second] = dist[node] + graph[node][i].second;
                pq.push({(dist[node] + graph[node][i].second), graph[node][i].second});
                par[graph[node][i].second] = node;
            }
        }
    }

    return dist;
}


int main()
{

    return 0;
}