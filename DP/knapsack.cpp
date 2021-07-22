#include<bits/stdc++.h>
using namespace std;



int knapsack(int n,int w,int* weight,int* profit)
{
	// base case
	if(n==0)
	{
		return 0;
	}
	if(w==0)
	{
		return 0;
	}

	if(weight[n-1] <= w)
	{
		return max(profit[n-1] + knapsack(n-1,w-weight[n-1],weight,profit) , knapsack(n-1,w,weight,profit));
	}

	return knapsack(n-1,w,weight,profit);
}

// DP
int knapsack2(int n,int w,int* weight,int* profit,int** output)
{
	if(n==0)
	{
		return 0;
	}
	if(w==0)
	{
		return 0;
	}
	if(output[n][w] > -1)
	{
		return output[n][w];
	}

	if(weight[n-1]<=w)
	{
		output[n][w]=max(profit[n-1]+knapsack2(n-1,w-weight[n-1],weight,profit,output),knapsack2(n-1,w,weight,profit,output));
	}
	else
	{
		output[n][w]=knapsack2(n-1,w,weight,profit,output);
	}
	return output[n][w];
}

int knapsack3(int n,int w,int* weight,int* profit)
{
	int** output = new int*[n+1] ;// rows(no of items)
	for(int i=0;i<=n;i++)
	{
		output[i]= new int[w+1];// weights
	}
	//base case
	for(int i=0;i<=w;i++)
	{
		output[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		output[i][0]=0;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			output[i][j]=output[i-1][j] ;// not including
			// if we are including
			if(weight[i-1] <= j)
			{
				output[i][j]=max(profit[i-1]+output[i-1][j-weight[i-1]],output[i-1][j]);
			}
		}
	}

	for(int i=0;i<=n;i++)
	{
		for(int  j=0;j<=w;j++)
		{
			cout << output[i][j] << " ";
		}
		cout << endl;
	}
	int ans = output[n][w];
	for(int i=0;i<=n;i++)
	{

		delete[] output[i];
	}
	delete output;
	return ans;
}

// space complexity o(W)
int knapsack4(int n,int W,int* weight,int* profit)
{
	int* output = new int[W+1]();

	for(int i=0;i<n;i++)
	{
		for(int j=W;j>=weight[i];j--)
		{
			output[j] = max(profit[i]+output[j-weight[i]],output[j]);
			cout << output[j] << " ";
		}
		cout << endl;
	}

	return output[W];
}


int main()
{
	int n,w;
	cin >> n >> w;
	int* weight = new int[n];
	int** output = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		output[i]=new int[w+1];
		for(int j=0;j<=w;j++)
		{
			output[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin >> weight[i];
	}
	int* profit = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> profit[i];
	}

	cout << knapsack3(n,w,weight,profit) << endl;
	cout << knapsack4(n,w,weight,profit) << endl;
}