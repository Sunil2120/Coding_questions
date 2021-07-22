#include<bits/stdc++.h>
using namespace std;
#define  MOD  1000000007
int solve(int** arr,int m,int n)
{
	long long** maxs = new long long*[m];
	long long** mins = new long long*[m];
	for(int i=0;i<m;i++)
	{
		maxs[i]=new long long[n];
		mins[i]=new long  long[n];
	}
	// base cases
	maxs[0][0]=arr[0][0];
	mins[0][0]=arr[0][0];

	// first col
	for(int i=1;i<m;i++)
	{
		maxs[i][0]=max(arr[i][0]*maxs[i-1][0],arr[i][0]*mins[i-1][0]);
		mins[i][0]=min(arr[i][0]*maxs[i-1][0],arr[i][0]*mins[i-1][0]);
	}
	// first row
	for(int i=1;i<n;i++)
	{
		maxs[0][i]=max(arr[0][i]*maxs[0][i-1],arr[0][i]*mins[0][i-1]);
		mins[0][i]=min(arr[0][i]*maxs[0][i-1],arr[0][i]*mins[0][i-1]);
	}
	for(int i=1;i<m;i++)
	{
		for(int j=1;j<n;j++)
		{
			// up
			long long max_1 = max(arr[i][j]*maxs[i-1][j],arr[i][j]*mins[i-1][j]);
			long long min_1 = min(arr[i][j]*maxs[i-1][j],arr[i][j]*mins[i-1][j]);
			//left
			long long max_2 = max(arr[i][j]*maxs[i][j-1],arr[i][j]*mins[i][j-1]);
			long long min_2 = min(arr[i][j]*maxs[i][j-1],arr[i][j]*mins[i][j-1]);
			maxs[i][j]=max(max_1,max_2);
			mins[i][j]=min(min_1,min_2);
		}
	}
	 int ans = maxs[m-1][n-1] < 0? -1:(maxs[m-1][n-1])%MOD;
       for(int i=0;i<m;i++)
       {
           delete[] maxs[i];
           delete[] mins[i];
       }
       delete[] maxs,mins;
       return ans;;


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
}