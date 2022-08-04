/*
*   author: rohanraut
*   created on: 11.09.2021 16:00:14
*/

#include <bits/stdc++.h>

using namespace std;

int findIndex(vector<int> &key, vector<bool> &mstSet){
	int minval=INT_MAX;
	int index;
	for(int i=0; i<key.size(); i++){
		if(key[i]<minval && mstSet[i]==false){
			minval=key[i];
			index=i;
		}
	}
	return index;
}

void prim(vector<vector<int>> &graph){
	vector<int> parent(5);
	vector<bool> mstSet(5,false);
	vector<int> key(5, INT_MAX);

	key[0]=0;
	parent[0]=-1;
	for(int i=0; i<5; i++){
		int u=findIndex(key,mstSet);
		mstSet[u]=true;
		for(int v=0; v<5; v++){
			if(graph[u][v]!=0 && mstSet[v]==false && key[u]+graph[u][v]<key[v]){
				parent[v]=u;
				key[v]=key[u]+graph[u][v];
			}
		}
	}

	
}


int main()
{
	int V = 5; //no. of vertices
    vector<vector<int>> graph = {{0, 2, 0, 6, 0}, {2, 0, 3, 8, 5}, {0, 3, 0, 0, 7}, {6, 8, 0, 0, 9}, {0, 5, 7, 9, 0}};

	prim(graph);

	return 0;
}