#include<bits/stdc++.h>
using namespace std;


int parties(int n,int limit,int* cost,int* fun)
{
	pair<int,int> output;

	if(n==0)
	{
		return 0;
	}
	if(limit==0)
	{
		return 0;
	}
	int total = 0;

	if(cost[n-1]<=limit)
	{
		int a = parties(n-1,limit-cost[n-1],cost,fun)+fun[n-1];
		int b = parties(n-1,limit,cost,fun);
		if(a>b)
		{
			total+=cost[n-1];
			return a;
		}
		return b;
	}
	return parties(n-1,limit,cost,fun);

}

void parties2(int n,int limit,int* cost,int* fun)
{
	int** output = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		output[i]=new int[limit+1];
	}

	for(int i=0;i<=limit;i++)
	{
		output[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		output[i][0]=0;
	}
	

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=limit;j++)
		{
			output[i][j]=output[i-1][j];
			if(cost[i-1]<=j)
			{
				int a = output[i-1][j-cost[i-1]] + fun[i-1];
				int b = output[i-1][j];
				if( a > b)
				{
					output[i][j]=a;
					
				}
				else
				{
					output[i][j]=b;
				}
			}
			else
			{
				output[i][j]=output[i-1][j];
			}
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=limit;j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}

	// int i=n;
	// int j=limit;
	// int result = output[i][j];
	int total = 0;
	// while(i>0 && j>0 && result > 0)
	// {
	// 	if(cost[i-1]<=j)
	// 	{
	// 		total+=cost[i-1];
	// 		result = result - fun[i-1];
	// 		if(output[i][j]==output[i-1][j])
	// 		{
	// 			i=i-1;
	// 		}
	// 		else
	// 		{
	// 			i=i-1;
	// 			j=j-cost[i-1];
	// 		}
	// 	}
	// 	else
	// 	{
	// 		i=i-1;
	// 	}
		
	// }
	int result = output[n][limit];
	int w = limit;
	for(int i=n;i>0 && result > 0;i--)
	{
		if(output[i-1][w]== result)
		{
			continue;
		}
		total+=cost[i-1];
		result = result - fun[i-1];
		w = w - cost[i-1];

	}



	cout << total << " " << output[n][limit] << endl;
	return ;
}

int main()
{
	int limit,n;
	cin >> limit >> n;
	int* cost = new int[n];
	int* fun = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> cost[i] >> fun[i];
	}
	parties2(n,limit,cost,fun);
	return 0;
}