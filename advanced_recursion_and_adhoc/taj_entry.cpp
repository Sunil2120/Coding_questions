#include<bits/stdc++.h>
using namespace std;


int solve(int arr[],int n)
{
	int* temp = new int[n];
	int j=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			temp[j++]= 0;
			continue;
		}
		if((arr[i]-i)%n==0)
		{
			temp[j++]=(arr[i]-i)/n;
		}
		else
		{
			temp[j++]= ((arr[i]-i)/n) + 1;
		}
	}
	int mi = temp[0];
	int min_index=0;
	for(int i=0;i<n;i++)
	{
		//cout << temp[i] << endl;
		if(temp[i] < mi)
		{
			mi=temp[i];
			min_index = i;
			//cout << min_index << endl;
		}
	}
	return min_index + 1;
}

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n) << endl;
	return 0;
}