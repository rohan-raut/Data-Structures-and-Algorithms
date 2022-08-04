/*
*   author: rohanraut
*   created on: 23.08.2021 12:51:38
*/

#include <bits/stdc++.h>

using namespace std;

// creating undirected graph
void createEdge(vector<vector<int>> &a, int u, int v)
{
	a[u].push_back(v);
	a[v].push_back(u);
}

// displaying graph
void display(vector<vector<int>> &a)
{
	for (int i = 0; i < a.size(); i++)
	{
		cout << i;
		for (int j = 0; j < a[i].size(); j++)
		{
			cout << "->" << a[i][j];
		}
		cout << endl;
	}
}

// bfs traversal
void bfs(vector<vector<int>> &a, int start)
{
	queue<int> q;
	vector<bool> visited(5, false);

	q.push(start);
	visited[start]=true;

	while(!q.empty()){
		start=q.front();
		cout<<start<<" ";
		q.pop();

		for(auto i=a[start].begin(); i!=a[start].end(); i++){
			if(visited[*i]==false){
				q.push(*i);
				visited[*i]=true;
			}
		}
	}
}

// function to find loops using bfs
int findLoops(vector<vector<int>> &a, int start){
	vector<int> visited(5,-1);
	queue<int> q;

	q.push(start);
	visited[start]=true;
	int count=0;

	while(!q.empty()){
		start=q.front();
		visited[start]=1;
		q.pop();

		for(auto i= a[start].begin(); i!=a[start].end(); i++){
			if(visited[*i]==0){
				count++;
			}
			if(visited[*i]==-1){
				q.push(*i);
				visited[*i]=0;
			}
		}
	}
	return count;
}

void mst(vector<vector<int>> a, int start){

}


int main()
{
	int v = 2;
	vector<vector<int>> a(v);

	// Graph Link: https://www.geeksforgeeks.org/graph-and-its-representations/
	// creating graph without weights
	// createEdge(a, 0, 1);
	// createEdge(a, 0, 4);
	// createEdge(a, 1, 4);
	// createEdge(a, 1, 3);
	// createEdge(a, 1, 2);
	// createEdge(a, 2, 3);
	// createEdge(a, 3, 4);

	createEdge(a,0,1);
	




	// bfs(a,2);
	cout<<"loops in graph: "<<findLoops(a,0)<<endl;

	return 0;
}