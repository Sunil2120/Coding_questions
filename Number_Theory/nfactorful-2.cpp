#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000

void create_arr(int* arr)
{
	for(int i=2;i<=MAX;i++)
	{
		if(arr[i]==0)// a prime number
		{
			arr[i]+=1;
			for(int j=2;j*i<=MAX;j++)// increamenting all its multiplies 
			{
				arr[j*i]+=1;
			}
		}
	}
	return ;
}

int main()
{
	int* arr = new int[MAX+1]();
	create_arr(arr);
	int** nfactors = new int*[11];// n can be max 10
	{
		for(int i=0;i<=10;i++)
		{
			nfactors[i]=new int[MAX+1]();
		}	
	}

	for(int i=0;i<=10;i++)
	{
		for(int j=1;j<=MAX;j++)
		{
			if(arr[j]==i)
			{
				nfactors[i][j]=nfactors[i][j-1]+1;
			}
			else
			{
				nfactors[i][j]=nfactors[i][j-1];
			}
		}
	}
	int t;
	cin >> t;
	while(t--)
	{
		int a,b,n;
		cin >> a >> b >> n;
		cout << nfactors[n][b] - nfactors[n][a-1] << endl;
	}
	for(int i=0;i<=10;i++)
	{
		delete[] nfactors[i];
	}
	delete[] nfactors;
	delete[] arr;
	return 0;
}