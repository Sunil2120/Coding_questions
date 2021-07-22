// to get the shortest path from source to destination
// since it is unweighted we will use dfs
#include<bits/stdc++.h>
using namespace std;


struct node
{
	int v,dis;
};

void printpath(map<int,int>& parent,int index)
{
	if(parent[index]==-1)//source
	{
		cout << index << endl;
		return ;
	}
	cout << index << " ";
	printpath(parent,parent[index]);
}

int solve(vector<int>& board,int n)
{
	vector<bool> visited(n,false);
	int output = 0;
	queue<node*> Q;
	node* temp = new node();
	temp->v = board[0];
	temp->dis=0;
	map<int,int> parent;
	parent[0]=-1;
	Q.push(temp);
	visited[0]=true;
	while(!Q.empty())
	{
		node* cur = Q.front();
		Q.pop();
		// check till 6 moves
		int start = cur->v+1;
		int end = cur->v+6;
		for(int i=start;i<=end && i < n;i++)
		{
			if(visited[board[i]]==true)
			{
				continue;
			}
			node* temp = new node();
			temp->v = board[i];
			temp->dis = cur->dis+1;
			Q.push(temp);
			parent[temp->v]=cur->v;
			visited[temp->v]=true;
			if((temp->v)==n-1)
			{
				output = temp->dis;
				break;
			}
		}
	}
	
	printpath(parent,n-1);
	return output;

}

int main()
{
	int n;
	cin >> n;
	vector<int> board(n,-1);
	for(int i=0;i<n;i++)
	{
		board[i]=i;
	}
	// ladders
	int l;
	cin >> l;
	for(int i=0;i<l;i++)
	{
		int a,b;
		cin >> a >> b;
		board[a]=b;
	}
	// snakes
	int s;
	cin >> s;
	for(int i=0;i<s;i++)
	{
		int a,b;
		cin >> a >> b;
		board[a]=b;
	}
	cout << solve(board,n) << endl;
	return 0;
}