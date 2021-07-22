#include<bits/stdc++.h>
using namespace std;


int get_count(int* arr,int n,int k)
{
	int* rem = new int[k]();
	int cur_sum = 0;
	for(int i=0;i<n;i++)
	{
		cur_sum+=arr[i];
		rem[(cur_sum%k + k)%k]+=1;// cur_sum can be negative
	}
	int count = 0;
	for(int i=0;i<k;i++)
	{
		if(rem[i] > 1)
		{
			count+=(rem[i]*(rem[i]-1))/2;
		}
	}
	count+=rem[0];
	return count;
}

int solve(int** arr,int n,int m,int k)
{
	int count = 0;
	for(int i=0;i<m;i++)
	{
		int* temp = new int[n]();
		for(int j=i;j<m;j++)
		{
			for(int k=0;k<n;k++)
			{
				temp[k]+=arr[k][j];
			}
			count+=get_count(temp,n,k);
		}
		delete[] temp;
	}
	return count;

}

int main()
{
	int n,m;
	cin >> n >> m;
	int** arr = new int*[n];
	for(int i=0;i<n;i++)
	{
		arr[i]=new int[m]();
		for(int j=0;j<m;j++)
		{
			cin >> arr[i][j];
		}
	}
	int k;
	cin >> k;
	cout << solve(arr,n,m,k) << endl;
	return 0;
}