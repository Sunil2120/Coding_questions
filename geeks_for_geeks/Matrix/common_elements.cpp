#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/common-elements-in-all-rows-of-a-given-matrix/
//O(m*n)
void solve(int** arr,int m,int n)
{
	unordered_map<int,int> hash;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(hash[arr[i][j]]==i)//eliminates duplicate and check whether it is has occured i items
			{
				hash[arr[i][j]]+=1;
			}
			if(i==m-1)
			{
				if(hash[arr[i][j]]==m)
				{
					cout << arr[i][j] << " ";
				}
			}
		}
	}
	cout << endl;
	return ;
}

int main()
{
	int m,n;
	cin >> m >> n;
	int** arr = new int*[m];
	for(int i=0;i<m;i++)
	{
		arr[i]=new int[n]();
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	solve(arr,m,n);
	return 0;
}