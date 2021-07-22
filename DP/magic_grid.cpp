#include<bits/stdc++.h>
using namespace std;



int magic_grid(int** arr,int si,int sj,int m,int n)
{

	int** output = new int*[m];
	for(int i=0;i<m;i++)
	{
		output[i]= new int[n];
		for(int j=0;j<n;j++)
		{
			output[i][j]=0;
		}
	}

	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	output[m-1][n-1]=1;
	for(int i=m-2;i>=0;i--)
	{
		output[i][n-1] = output[i+1][n-1] - arr[i+1][n-1];
	}

	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;

	for(int j=n-2;j>=0;j--)
	{
		output[m-1][j] = output[m-1][j+1] - arr[m-1][j+1];
	}

	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << endl;


	for(int i=m-2 ;i>=0;i--)
	{
		for(int j=n-2;j>=0 ;j--)
		{
			int right = output[i][j+1] - arr[i][j+1];
			if(right <=0)
			{
				right = 1;
			}
			int left = output[i+1][j] - arr[i+1][j];
			if(left <=0)
			{
				left = 1;
			}
			output[i][j] = min(right,left);
		}
	}

	// for(int i=0;i<m;i++)
	// {
	// 	for(int j=0;j<n;j++)
	// 	{
	// 		cout << output[i][j] << " ";
	// 	}
	// 	cout << endl ;
	// }
	// cout << endl;

	int ans = output[0][0];
	delete []output;

	return ans;

	
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m,n;
		cin >> m >> n;
		int** arr = new int*[m];
		for(int i=0;i<m;i++)
		{
			arr[i] = new int[n];
			for(int j=0;j<n;j++)
			{
				cin >> arr[i][j];
			}
		}

		cout << magic_grid(arr,0,0,m,n) << endl;
		delete []arr;

	}
	
	return 0;
}