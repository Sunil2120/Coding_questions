// Detecting_cylce_using_BFS

//  for Directed graph
// time O(V+E)
// Step-1: Compute in-degree (number of incoming edges) for each of the vertex present in the graph and initialize the count of visited nodes as 0.

// Step-2: Pick all the vertices with in-degree as 0 and add them into a queue (Enqueue operation)

// Step-3: Remove a vertex from the queue (Dequeue operation) and then.

// Increment count of visited nodes by 1.
// Decrease in-degree by 1 for all its neighboring nodes.
// If in-degree of a neighboring nodes is reduced to zero, then add it to the queue.
// Step 4: Repeat Step 3 until the queue is empty.

// Step 5: If count of visited nodes is not equal to the number of nodes in the graph has cycle, otherwise not.


#include<bits/stdc++.h>
using namespace std;

bool solve(map<int,vector<int>>& adj,int m,int n,vector<int>& indegree)
{
	queue<int> Q;
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
		{
			Q.push(i);
		}
	}
	int count = 0;
	while(!Q.empty())
	{
		int cur = Q.front();
		count+=1;
		Q.pop();
		// exploring it's neighbours
		for(int i=0;i<adj[cur].size();i++)
		{
			int next = adj[cur][i];
			indegree[next]-=1;
			if(indegree[next]==0)
			{
				Q.push(next);
			}
		}
	}
	if(count==n)
	{
		return false;
	}
	return true;
}

int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> indegree;
	indegree.assign(n,0);
	map<int,vector<int>> adj;
	for(int i=0;i<m;i++)
	{
		int f,s;
		cin >> f >> s;
		adj[f].push_back(s);
		indegree[s]+=1;
	}
	cout << solve(adj,m,n,indegree);
}
