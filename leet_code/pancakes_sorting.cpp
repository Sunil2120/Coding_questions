#include<bits/stdc++.h>
using namespace std;

void flip(vector<int>& arr,int index,int n)
{
	int i = 0;
	int j= index;
	while( i < n && j >=0 && i < j)
	{
		swap(arr[i],arr[j]);
		i++;
		j--;
	}
	return ;
}


void solve(vector<int>& arr,int n)
{
	if(n==0)
	{
		return ;
	}
	vector<int> output;
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]==i+1)
		{
			continue;
		}
		// we will find the index of largest elemnt.
		int j;
		for(j=0;j<n;j++)
		{
			if(arr[j]==i+1)
			{
				break;
			}
		}
		if(j!=0)
		{
			flip(arr,j,n);
			output.push_back(j+1);
		}
		flip(arr,i,n);
		output.push_back(i+1);
	}

	for(int i=0;i<n;i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr;
	for(int i=0;i<n;i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}
	solve(arr,n);
	return 0;
}