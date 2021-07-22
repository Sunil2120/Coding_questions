#include<bits/stdc++.h>
using namespace std;


int solve(int** input,int row,int col)
{
	int** output = new int*[row];
	for(int i=0;i<row;i++)
	{
		output[i]=new int[col]();
	}
// first col intialized
	for(int i=0;i<row;i++)
	{
		if(input[i][0] == 1)
		{
			output[i][0] = 0;
		}
		else if(input[i][0] == 0)
		{
			output[i][0] = 1;
		}
	}
// first row intialized
	for(int i=0;i<col;i++)
	{
		if(input[0][i] == 1)
		{
			output[0][i] = 0;
		}
		else if(input[0][i] == 0)
		{
			output[0][i] = 1;
		}
	}
	int max_ = 1;
	for(int i=1;i<row;i++)
	{
		for(int j=1;j<col;j++)
		{
			if(input[i][j]==1)
			{
				output[i][j]=0;
			}
			else
			{
				output[i][j] = min(output[i-1][j-1],min(output[i][j-1],output[i-1][j])) + 1;
				if(output[i][j] > max_)
				{
					max_ = output[i][j];
				}
			}
		}
	}

	delete[] output;

	return max_;


}


int main()
{
	int m,n;
	cin >> m >> n;
	int** input = new int*[m];// rows
	for(int i=0;i<m;i++)
	{
		input[i]=new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> input[i][j];
		}
	}

	cout << solve(input,m,n) << endl;
	delete[] input;
	return 0;
}