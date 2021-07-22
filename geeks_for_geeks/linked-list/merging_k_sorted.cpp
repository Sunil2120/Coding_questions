#include<bits/stdc++.h>

using namespace std;

struct node
{	
	int data;
	int row;
	int index;
};
typedef struct node node;

class myComparator{
	
	public:
		int operator()(const node& a,const node& b)
		{
			return a.data > b.data;
		}
};

void solve(vector<vector<int>> input,int n)
{
	priority_queue<node,vector<node>,myComparator> Q;
	for(int i=0;i<n;i++)
	{
		node temp;
		temp.data = input[i][0];
		temp.row = i;
		temp.index = 0;
		Q.push(temp);
	}
	vector<int> output;
	while(!Q.empty())
	{
		node cur = Q.top();
		Q.pop();
		output.push_back(cur.data);
		if(cur.index + 1 < input[cur.row].size())
		{
			node temp;
			temp.data = input[cur.row][cur.index+1];
			temp.row = cur.row;
			temp.index = cur.index+1;
			Q.push(temp);
		}
	}
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
	return ;

}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> input;
	for(int i=0;i<n;i++)
	{
		int m;
		cin >> m;
		vector<int> temp;
		for(int j=0;j<m;j++)
		{
			int value;
			cin >> value;
			temp.push_back(value);
		}
		input.push_back(temp);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<input[i].size();j++)
		{
			cout << input[i][j] << " ";
		}
		cout << endl;
	}
	solve(input,n);
	return 0;
}