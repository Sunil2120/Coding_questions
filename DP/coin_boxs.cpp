#include<bits/stdc++.h>
using namespace std;


// void solve(int n,int m,int q,int* left,int* right,int* queries)
// {
// 	int* output = new int[n+1]();
// 	// for(int i=0;i<m;i++)
// 	// {
// 	// 	for(int j=left[i];j<=right[i];j++)
// 	// 	{
// 	// 		output[j]+=1;
// 	// 	}
// 	// }
// 	for(int i=0;i<m;i++)
// 	{

// 	}

// 	for(int i=0;i<q;i++)
// 	{
// 		int count = 0;
// 		for(int j=1;j<=n;j++)
// 		{
// 			if(output[j] >= queries[i])
// 			{
// 				count+=1;
// 			}
// 		}
// 		cout << count << endl;
// 	}
// 	return ;
// }

void solve2(int n,int m,int q,int* left,int* right,int* queries)
{
	int* start = new int[n+1]();
	int* end = new int[n+1]();
	for(int i=0;i<m;i++)
	{
		start[left[i]]+=1;
		end[right[i]]+=1;
	}
	int* boxes = new int[n+1](); // number of coins in the each n boxes
	boxes[1]= start[1];
	for(int i=2;i<=n;i++)
	{
		boxes[i]=start[i]+boxes[i-1]-end[i-1];
	}

	int* no_coins = new int[n+1](); // total no of i coins 
	for(int i=1;i<=n;i++)
	{
		no_coins[boxes[i]]+=1;
	}
	int* atleast_coins = new int[n+1](); // atleast i coins
	atleast_coins[n]=no_coins[n];
	for(int i=n-1;i>=1;i--)
	{
		atleast_coins[i] = no_coins[i]+atleast_coins[i+1];
	}
	for(int i=0;i<q;i++)
	{
		cout << atleast_coins[queries[i]] << endl;
	}
	delete[] boxes;
	delete[] start;
	delete[] end;
	delete[] no_coins;
	delete[] atleast_coins;
	return ;
}

int main()
{
	int n,m,q;
	cin >> n >> m;
	int* left = new int[m]();
	int* right = new int[m]();
	
	for(int i=0;i<m;i++)
	{
		cin >> left[i] >> right[i];
	}
	cin >> q;
	int* queries = new int[q]();
	for(int i=0;i<q;i++)
	{
		cin >> queries[i];
	}
	solve2(n,m,q,left,right,queries);
	delete[] left;
	delete[] right;
	delete[] queries;
	return 0;
}