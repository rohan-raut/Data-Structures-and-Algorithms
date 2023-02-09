/*
	Bellman Ford Single Source Shortest Path Algo
	In this algo we need to store list of edges through which we will iterate n-1 times
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> bellman(vector<vector<int>> edges, int n, int src){
	vector<int> dist(n+1, 1e7);
	dist[src] = 0;

	for(int i=0; i<n-1; i++){
		for(int j=0; j<edges.size(); j++){
			int u = edges[j][0];
			int v = edges[j][1];
			int wt = edges[j][2];
			if(dist[u] + wt < dist[v]){
				dist[v] = dist[u] + wt;
			}
		}
	}

	// Relax one more time to check if the distance array remains the same, if it changes then the graph contains negative wt. cycle

	return dist;
}

int main()
{

	
	
	return 0;
}