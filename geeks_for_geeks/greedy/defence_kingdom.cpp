#include<bits/stdc++.h>
using namespace std;

int solve(int** grid,int h,int w,int n)
{

	int** dp = new int*[h];
	for(int i=0;i<h;i++)
	{
		dp[i]=new int[w];
		for(int j=0;j<w;j++)
		{
			dp[i][j]=0;
		}
	}
	for(int i=0;i<w;i++)
	{
		if(grid[0][i]==0)
		{
			grid[0][i]=1;
		}
		else
		{
			grid[0][i]=0;
		}
	}
	for(int i=1;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			if(grid[i][j]==1)
			{
				grid[i][j]=0;
			}
			else
			{
				grid[i][j]=grid[i-1][j]+1;
			}
		}
	}
	for(int i=0;i<h;i++)
	{
		stack<int> left;
		stack<int> right;
		vector<int> l(w);
		vector<int> r(w);
		l[0]=-1;
		left.push(0);
		for(int j=1;j<w;j++)
		{
			// pop until we get element less than cur elemnt
			while(left.size() > 0 && grid[i][left.top()] >= grid[i][j])
			{
				left.pop();
			} 
			if(left.size()==0)
			{
				l[j]=-1;
			}
			else
			{
				l[j]=left.top();
			}
			left.push(j);
		}
		r[w-1]=w;
		right.push(w-1);
		for(int j=w-2;j>=0;j--)
		{
			while(right.size() > 0 && grid[i][right.top()] >= grid[i][j])
			{
				right.pop();
			}
			if(right.size()==0)
			{
				r[j]=w;
			}
			else
			{
				r[j]=right.top();
			}
			right.push(j);
		}
		for(int j=0;j<w;j++)
		{
			dp[i][j]=(grid[i][j])*(r[j]-l[j]+1-2);
		}
	}
	int max_value = INT_MIN;
	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			max_value = max(max_value,dp[i][j]);
		}
		
	}
	for(int i=0;i<h;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return max_value;
	
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int w,h,n;
		cin >> w >> h >> n;
		int** grid = new int*[h];
		for(int i=0;i<h;i++)
		{
			grid[i]=new int[w];
			for(int j=0;j<w;j++)
			{
				grid[i][j]=0;
			}
		}
		for(int i=0;i<n;i++)
		{
			int a,b ;
			cin >> a >> b;
			for(int i=0;i<h;i++)
			{
				grid[i][a-1]=1;
			}
			for(int i=0;i<w;i++)
			{
				grid[b-1][i]=1;
			}
		}
		cout << solve(grid,h,w,n) << endl;
		for(int i=0;i<h;i++)
		{
			delete[] grid[i];
		}
		delete[] grid;
	}
	return 0;
}