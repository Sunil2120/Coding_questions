#include<bits/stdc++.h>
using namespace std;

// int solve(int** input,int m,int n,int row,int prev)
// {
// 	if(n==0)
// 	{
// 		return 0;
// 	}
// 	if(row >= m)
// 	{
// 		return prev;
// 	}
// 	int min_ = 100000;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(input[row][i]==prev+1 || input[row][i]==prev || input[row][i]==prev-1)
// 		{
// 			continue;
// 		}
// 		if(input[row][i] < min_)
// 		{
// 			min_ = input[row][i];
// 		}
// 	}
// 	//cout  << prev << endl;
// 	int sum = prev + solve(input,m,n,row+1,min_);

// 	return sum;
// }


int solve2(int** input,int m,int n,int row,int col)
{
	if(n==0)
	{
		return 0;
	}
	if(row >= m)
	{
		return 0;
	}
	if(col < 0 || col >= n || row <0 || row >=m)
	{
		return 100000000;
	}
	int temp = solve2(input,m,n,row+1,col-1);
	int temp1 = solve2(input,m,n,row+1,col+1);
	int temp2 = solve2(input,m,n,row+1,col);
	return min(temp,min(temp1,temp2)) + input[row][col];
}

int solve3(int** input,int m,int n)
{

	int** output = new int*[m];
	for(int i=0;i<m;i++)
	{
		output[i]=new int[n];
	}
	for(int i=0;i<n;i++)
	{
		output[m-1][i]=input[m-1][i];
	}

	for(int i=m-2;i>=0;i--)
	{
		for(int j=n-1;j>=0;j--)
		{
			int temp1,temp2,temp3;
			int result ;
			if(j==n-1)
			{
				temp1 = output[i+1][j-1];
				temp2 = output[i+1][j];
				output[i][j]=min(temp1,temp2) + input[i][j];
				continue;
			}
			else if(j==0)
			{
				temp2 = output[i+1][j+1];
				temp3 = output[i+1][j];
				output[i][j]=min(temp2,temp3)+input[i][j];
				continue;

			}

			temp1 = output[i+1][j-1];
			temp2 = output[i+1][j+1];
			temp3 = output[i+1][j];
			output[i][j]=min(temp1,min(temp2,temp3)) + input[i][j];
		}
	}
	int min_x = INT_MAX;
	for(int i=0;i<n;i++)
	{
		if(output[0][i] < min_x)
		{
			min_x = output[0][i];
		}
	}
	for(int i=0;i<m;i++)
	{
		delete[] output[i];
	}
	delete[] output;
	return min_x;
}
int main()
{
	int n,m;
	cin >> m >> n;
	int** input = new int*[m];
	for(int i=0;i<m;i++)
	{
		input[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> input[i][j];
		}
	}
	cout << solve3(input,m,n) << endl;
	for(int i=0;i<m;i++)
	{
		delete[] input[i];
	}
	delete[] input;
	return 0;
}