#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,m;
	cin >> m >> n;
	int** output = new int*[m];
	int** input = new int*[m]; // row
	for(int i=0;i<m;i++)
	{
		input[i]= new int[n];//column
		output[i]=new int[n]();
		for(int j=0;j<n;j++)
		{
			cin >> input[i][j];

		}
	}

	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0)
			{
				output[i][j]=1;
				continue;
			}
			if(input[i][j] >= input[i-1][j])
			{
				output[i][j] = output[i-1][j] + 1;
			}
			else
			{
				output[i][j]=1;
			}

		}
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >> r;
		l=l-1;
		r=r-1;
		int value = r - l + 1;
		int j;
		for(j=0;j<n;j++)
		{
			if(output[r][j] >= value)
			{
				cout << "yes" << endl;
				break;
			}
		}
		if(j>=n)
		{
			cout << "no" << endl;
		}
	}

	return 0;


}