#include<bits/stdc++.h>
using namespace std;


int getcount(vector<int>& arr,int n)
{
	int count = 0;
	for(int i=1;i<=n-2;i++)
	{
		if((arr[i] > arr[i-1] && arr[i] > arr[i+1]) || (arr[i] < arr[i-1] && arr[i] < arr[i+1]))
		{
			count+=1;
		}
	}
	return count;
}

int solve(vector<int>& arr,int n)
{
	vector<int> store(n,0);
	int count = 0;
	for(int i=1;i<=n-2;i++)
	{
		if((arr[i-1] > arr[i] && arr[i+1] > arr[i]) || (arr[i-1] < arr[i] && arr[i+1] < arr[i]))
		{
			store[i]=1;
			count+=1;
		}
	}
	//cout << count << endl;
	int min_value = INT_MAX;
	for(int i=1;i<=n-2;i++)
	{
		int temp_count = count;
		//change it to left
		int temp = arr[i];
		arr[i]=arr[i-1];
		// first we will check whether cur is hill or not
		if(store[i]==1)
		{
			temp_count-=1;
		}
		// we will check the left one
		if(store[i-1]==1)
		{
			temp_count-=1;
		}
		//check right one
		if( i+2 < n && ((arr[i+2] < arr[i+1] && arr[i] < arr[i+1]) || (arr[i+2] > arr[i+1] && arr[i] > arr[i+1])))
		{
			temp_count+=1;
		}
		if(store[i+1]==1)
		{
			temp_count-=1;
		}
		min_value = min(min_value,temp_count);
		// change it to right
		temp_count = count;
		arr[i]=arr[i+1];
		// first we will check whether cur is hill or not
		if(store[i]==1)
		{
			temp_count-=1;
		}
		// we will check the right one
		if(store[i+1]==1)
		{
			temp_count-=1;
		}
		//check the left one
		if( i-2 >=0 && ((arr[i] < arr[i-1] && arr[i-2] < arr[i-1]) || (arr[i] > arr[i-1] && arr[i-2] > arr[i-1])))
		{
			temp_count+=1;
		}
		if(store[i-1]==1)
		{
			temp_count-=1;
		}
		min_value = min(min_value,temp_count);
		arr[i]=temp;
		//cout << arr[i] << " " << min_value << endl;
	}
	return min_value;
}





int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> arr(n);
		for(int i=0;i<n;i++)
		{
			cin >> arr[i];
		}
		cout << solve(arr,n) << endl;
	}
	return 0;
}