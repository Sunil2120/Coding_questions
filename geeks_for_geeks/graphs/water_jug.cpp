#include<bits/stdc++.h>
using namespace std;



void bfs(int a,int b,int d)
{
	queue<pair<int,int>> Q;
	map<pair<int,int>,int> visited;
	Q.push(make_pair(0,0));//intial state
	int check = 0;
	vector<pair<int,int>> path;
	while(!Q.empty())
	{
		pair<int,int> cur = Q.front();
		Q.pop();
		// if already visited
		if(visited[{cur.first,cur.second}]==1)
		{
			continue;
		}
		//state not allowed
		if(cur.first > a || cur.first < 0 || cur.second > b || cur.second < 0)
		{
			continue;
		}

		visited[{cur.first,cur.second}]=1;
		path.push_back(cur);

		// check if cur is target 
		if(cur.first ==d || cur.second==d)
		{
			if(cur.first==d && cur.second >= 0)
			{
				path.push_back(make_pair(cur.first,0));
			}
			if(cur.second==d && cur.first >=0)
			{
				path.push_back(make_pair(0,cur.second));
			}
			for(int i=0;i<path.size();i++)
			{
				cout << path[i].first << " " << path[i].second << endl;
			}
			check = 1;
			return ;
		}

		// condition 1 fill a jug
		Q.push(make_pair(a,cur.second));
		Q.push(make_pair(cur.first,b));

		//  condition 2 empty a jug
		Q.push(make_pair(0,b));
		Q.push(make_pair(a,0));

		// condition 3 fill water from one jug to another until one of them is full or one of them empty
		for(int i=1;i<=max(a,b);i++)
		{
			int temp1 = cur.first-i;
			int temp2 = cur.second+i;
			if((temp2==b && temp1>=0) || (temp1==0 && temp2 <=b))
			{
				Q.push(make_pair(temp1,temp2));
			}
			temp1 = cur.first + i;
			temp2 = cur.second - i;
			if((temp1==a && temp2 >=0) || (temp2==0 && temp1 <=a))
			{
				Q.push(make_pair(temp1,temp2));
			}
		}

	}
	if(check==0)
	{
		cout << "NO solution" << endl;
	}
	return ;
}
int main()
{
	int a,b,d;
	cin >> a >> b >> d;
	bfs(a,b,d);
	return 0;
}