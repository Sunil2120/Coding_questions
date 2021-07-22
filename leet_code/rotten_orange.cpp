#include<bits/stdc++.h>
using namespace std;


struct node
{
	int time_frame =0;
	int x;
	int y;
};
typedef struct node node;


int solve(vector< vector<int> >& input,int m,int n)
{
	queue<node*> Q;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(input[i][j]==2)//rotten
			{
				node* temp=new node();
				temp->time_frame = 0;
				temp->x = i;
				temp->y = j;
				Q.push(temp); 
			}
		}
	}
	node* cur = NULL;
	while(!Q.empty())// until queue becomes empty
	{
		cur = Q.front();
		Q.pop();
		int r = cur->x;
		int c = cur->y;
		int t = cur->time_frame;
		// left
		if(c-1>=0 && input[r][c-1]==1)
		{
			node* temp = new node();
			temp->time_frame = t+1;
			temp->x = r;
			temp->y = c-1;
			input[r][c-1]=2;
			Q.push(temp);
		}
		// right
		if(c+1<n && input[r][c+1]==1)
		{
			node* temp = new node();
			temp->time_frame = t+1;
			temp->x = r;
			temp->y = c+1;
			input[r][c+1]=2;
			Q.push(temp);
		}
		// up
		if(r-1>=0 && input[r-1][c]==1)
		{
			node* temp = new node();
			temp->time_frame = t+1;
			temp->x = r-1;
			temp->y = c;
			input[r-1][c]=2;
			Q.push(temp);
		}
		// down
		if(r+1<m && input[r+1][c]==1)
		{
			node* temp = new node();
			temp->time_frame = t+1;
			temp->x = r+1;
			temp->y = c;
			input[r+1][c]=2;
			Q.push(temp);
		}
	}
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(input[i][j]==1)
			{
				return -1;
			}
		}
	}
	if(cur==NULL)// no rotten oranges basket contains only 1 and 0 or only 1 or only 2 (Q will be empty)
	{
		return 0;// 1 contains is taken care above
	}
	return cur->time_frame;
}
int main()
{
	int m,n;
	cin >> m >> n;
	vector< vector<int> > input;
	for(int i=0;i<m;i++)
	{
		vector<int> temp;
		for(int j=0;j<n;j++)
		{
			int value;
			cin >> value;
			temp.push_back(value);
		}
		input.push_back(temp);
	}
	cout << solve(input,m,n) << endl;
	return 0;

}