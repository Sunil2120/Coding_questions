// #include<bits/stdc++.h>
// using namespace std;

// void print_cycle()

// bool solve(map<int,vector<int>>& adj,int n,int m)
// {
// 	vector<int> parent;
// 	vector<bool> visited;
// 	queue<int> Q;
// 	Q.push(0);
// 	parent.assign(n,-1);
// 	visited.assign(n,false);
// 	visited[0]=true;
// 	while(!Q.empty())
// 	{
// 		int cur = Q.front();
// 		Q.pop();
// 		// explore it's neighbours
// 		for(int i=0;i<adj[cur].size();i++)
// 		{
// 			int next = adj[cur][i];
// 			if(next==parent[cur])
// 			{
// 				continue;
// 			}
// 			if(visited[next]==true)// already visited
// 			{
// 				return true;
// 			}
// 			visited[next]=true;
// 			parent[next]=cur;
// 			Q.push(next);
// 		}
// 	}
// 	return false;
// }

// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;

// Stores the vertices
int store[MAX], n1;

// Graph
int graph[MAX][MAX];

// Degree of the vertices
int d[MAX];

// Function to check if the given set of
// vertices in store array is a clique or not
bool is_clique(int b)
{

	// Run a loop for all set of edges
	for (int i = 1; i < b; i++) {
		for (int j = i + 1; j < b; j++)

			// If any edge is missing
			if (graph[store[i]][store[j]] == 0)
				return false;
	}
	return true;
}

// Function to find all the sizes
// of maximal cliques
int maxCliques(int i, int l)
{
	// Maximal clique size
	int max_ = 0;

	// Check if any vertices from i+1
	// can be inserted
	for (int j = i + 1; j <= n1; j++) {

		// Add the vertex to store
		store[l] = j;

		// If the graph is not a clique of size k then
		// it cannot be a clique by adding another edge
		if (is_clique(l + 1)) {

			// Update max
			max_ = max(max_, l);

			// Check if another edge can be added
			max_ = max(max_, maxCliques(j, l + 1));
		}
	}
	return max_;
}

void solve(int* f,int* s,int n,unordered_map<int,vector<int>>& m)
{
	unordered_map<int,vector<int>> m2;
	for(int i=0;i<n;i++)
	{
		m2[f[i]].push_back(i);
		for(int j=0;j<n;j++)
		{
			if(s[j]==f[i])
			{
				m2[f[i]].push_back(j);
			}
		}
	}

	unordered_map<int,vector<int>>::iterator it;
	for(it=m2.begin();it!=m2.end();it++)
	{
		vector<int> temp1=it->second;
		unordered_map<int,vector<int>>::iterator it2;
		for(it2=m2.begin();it2!=m2.end();it2++)
		{
			if(it2==it)
			{
				continue;
			}
			vector<int> temp=it2->second;
			if(temp[0]<=temp1[0] && temp[1]>=temp1[1])
			{
				m[it->first].push_back(it2->first);
			}
			else if(temp[0]>=temp1[0] && temp[1]<=temp1[1])
			{
				m[it->first].push_back(it2->first);
			}
		}


	}
	return;
}


// Driver code
void solve4(int n,unordered_map<int,vector<int>>& adj)
{
	unordered_map<int,vector<int>>::iterator it;
	vector<vector<int>> edges;
	for(it=adj.begin();it!=adj.end();it++)
	{
		//cout << it->first << " ";
		vector<int> temp=it->second;
		
		for(int i=0;i<temp.size();i++)
		{
			vector<int> temp2;
			//cout << temp[i] << " ";
			temp2.push_back(it->first);
			temp2.push_back(temp[i]);
			edges.push_back(temp2);


		}
		//cout << endl;
	}
	



    // int edges[][2] = { { 1, 2 }, { 2, 3 }, { 3, 1 }, 
    //                    { 4, 3 }, { 4, 1 }, { 4, 2 } };
    int size = edges.size();
    n1= n;
    for(int i=0;i<MAX;i++)
    {
    	store[i]=0;
    	d[i]=0;
    	for(int j=0;j<MAX;j++)
    	{
    		graph[i][j]=0;
    	}
    }
  
    for (int i = 0; i < size; i++) {
    	if(graph[edges[i][0]][edges[i][1]]==1)
    	{
    		continue;
    	}
        graph[edges[i][0]][edges[i][1]] = 1;
        graph[edges[i][1]][edges[i][0]] = 1;
        d[edges[i][0]]++;
        d[edges[i][1]]++;
    }
  
    cout << maxCliques(0, 1);

	return ;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin>>n;
		int* f=new int[n]();
		int* s=new int[n]();
		for(int i=0;i<n;i++)
		{
			cin >> f[i];
		}
		for(int i=0;i<n;i++)
		{
			cin >> s[i];
		}
		unordered_map<int,vector<int>> m;
		solve(f,s,n,m);
		solve4(n,m);
		cout << endl;
	}
	
	return 0;

}




// int main()
// {
// 	int n,m;
// 	cin >> n >> m;
// 	map<int,vector<int>> adj;
// 	for(int i=0;i<m;i++)
// 	{
// 		vector<int> temp;
// 		int start;
// 		cin >> start;
// 		int count ;
// 		cin >> count;
// 		for(int i=0;i<count;i++)
// 		{
// 			int value;
// 			cin >> value;
// 			temp.push_back(value);
// 		}
// 		adj[start]=temp;
// 	}
// 	cout << solve3(adj,n) << endl;
// }