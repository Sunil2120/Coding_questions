#include<bits/stdc++.h>
using namespace std;



// recurrsively o(pow(3,m)) 
int min_cost(int** arr,int si,int sj,int di,int dj)
{
	if(si==di && sj==dj)
	{
		return arr[di][dj];
	}

	// boundaries
	if(si > di || sj >  dj)
	{
		return INT_MAX; // maximum because we are finding minimum
	}

	int right = min_cost(arr,si,sj+1,di,dj);
	int down = min_cost(arr,si+1,sj,di,dj);
	int diagonal= min_cost(arr,si+1,sj+1,di,dj);

	return arr[si][sj] + min(right, min(down,diagonal));

}

// Dynamic programming recurrsively

int min_cost2(int** arr,int si,int sj,int di,int dj,int** suni)
{
	if(si==di && sj==dj)
	{
		return arr[di][dj];
	}

	// boundaries
	if(si > di || sj >  dj)
	{
		return INT_MAX; // maximum because we are finding minimum
	}

	if(suni[si][sj] > -1)
	{
		return suni[si][sj];
	}

	int right = min_cost2(arr,si,sj+1,di,dj,suni);
	int down = min_cost2(arr,si+1,sj,di,dj,suni);
	int diagonal= min_cost2(arr,si+1,sj+1,di,dj,suni);

	suni[si][sj] = arr[si][sj] + min(right, min(down,diagonal));

	return suni[si][sj];
}

// Dynamic programming iterative solution

int min_cost3(int** input,int m,int n)
{
	int** output = new int*[m]; // row
	for(int i=0;i<m;i++)
	{
		output[i]=new int[n]; // column
	}

	output[m-1][n-1] = input[m-1][n-1]; // destination node
	// right most column

	for(int i=m-2;i>=0;i--)
	{
		output[i][n-1] = output[i+1][n-1] + input[i][n-1];
	}

	// bottom row

	for(int j=n-2;j>=0;j--)
	{
		output[m-1][j] = output[m-1][j+1] + input[m-1][j];
	}

	// other boxs

	for(int i=m-2 ;i>=0 ;i--)
	{
		for(int j=m-2;j>=0;j--)
		{
			output[i][j] = input[i][j] + min(output[i][j+1],min(output[i+1][j],output[i+1][j+1]));
		}
	}
	int ans = output[0][0];
	delete []output;
	return ans;
}


int main()
{
	int n;
	cin >> n;
	int** input = new int*[n];
	for(int i=0;i<n;i++)
	{
		input[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> input[i][j];
		}
	}

	int** output = new int*[n];

	for(int i=0;i<n;i++)
	{
		output[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			output[i][j] = -1;
		}
	}
	cout << min_cost(input,0,0,n-1,n-1) << endl;
	cout << min_cost2(input,0,0,n-1,n-1,output) << endl;
	cout << min_cost3(input,3,3) << endl;
	return 0;
}