#include<bits/stdc++.h>
using namespace std;


int solve(int** arr,int m,int n)
{
	int* counts = new int[m];
	for(int i=0;i<m;i++)
	{
		int j = n-1;
		int count = 0;
		while(arr[i][j]==0 && j>=0)
		{
			count+=1;
			j--;
		}
		counts[i]=count;
	}
	for(int i=0;i<m;i++)
	{
		cout << counts[i] << " ";
	}
	cout << endl;
	int swaps = 0;
	for(int i=0;i<m-1;i++)
	{
		int desired = (n-i-1);// we need these number of zeros here
		if(counts[i]>=desired)
		{
			continue;
		}
		int j;
		for(j=i+1;j<m;j++)
		{
			if(counts[j]>=desired)
			{
				break;
			}
		}
		if(j==m)
		{
			return -1;
		}
		// we will swap  i and j
		for(int k=j;k>=i+1;k--)
		{
			int temp = counts[k];
			counts[k]=counts[k-1];
			counts[k-1]=temp;
		}
		swaps+=(j-i);
		
	}
	for(int i=0;i<m;i++)
	{
		cout << counts[i] << " ";
	}
	cout << endl;
	
	delete[] counts;
	return swaps;
}

int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	cout << solve(arr,m,n) << endl;
	return 0;
}