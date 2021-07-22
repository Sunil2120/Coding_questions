#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = new int[n];
		for(int j=0;j<n;j++)
		{
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<n;i++)
	{
		if(i%2==0)
		{
			for(int j=0;j<n;j++)
			{
				cout << arr[j][i] << " ";
			}
			cout << endl;
		}
		else
		{
			for(int j=n-1;j>=0;j--)
			{
				cout << arr[j][i] << " ";
			}
			cout << endl;

		}
	}

	for(int i=0;i<n;i++)
	{
		delete arr[i]; 
	}
}