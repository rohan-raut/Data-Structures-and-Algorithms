/*
*   author: rohanraut
*   created on: 23.08.2021 20:15:31
*/

// DSU Methot to find loops in graph
// Youtube link 1: https://www.youtube.com/watch?v=C0O8T3C8irU
// Youtube link 2: https://www.youtube.com/watch?v=YZ40AZQi0bk&t=319s

#include <bits/stdc++.h>

using namespace std;

vector<int> parent(20);
vector<int> sz(20, 1);

int find_set(int v)
{
	if (v == parent[v])
	{
		return v;
	}
	return parent[v] = find_set(parent[v]);
}

void union_set(int a, int b)
{
	a = find_set(a);
	b= find_set(b);
	if(a!=b){
		if(sz[a]<sz[b]){
			swap(a,b);
		}
		parent[b]=a;
		sz[a]=sz[a]+sz[b];
	}
}

int main()
{

	for (int i = 0; i < parent.size(); i++)
	{
		parent[i] = i;
	}

	int e, v;
	cin >> e;
	vector<vector<int>> edge;

	for (int i = 0; i < e; i++)
	{
		int u, v;
		cin >> u >> v;
		edge.push_back({u, v});
	}

	bool cycle = false;
	int count=0;
	for (int i = 0; i < edge.size(); i++)
	{
		int x = find_set(edge[i][0]);
		int y = find_set(edge[i][1]);
		if (x == y)
		{
			cycle = true;
			count++;
		}
		else
		{
			union_set(x, y);
		}
	}

	if(cycle){
		cout<<"cycle found: "<<count<<endl;
	}
	else{
		cout<<"cycle not found"<<endl;
	}

	return 0;
}