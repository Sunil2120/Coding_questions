#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& input,int n)
{
	if(n==0)
	{
		return 0;
	}
	unordered_map<int,bool> hash;
	sort(input.begin(),input.end());
	for(int i=n-1;i>=0;i--)
	{
		int low = i+1;
		int high = n-1;
		int ans = -1;
		while(low <= high)
		{
			int mid = low + (high-low)/2;
			if(input[mid] >= input[i]*2 && hash[mid]==false)
			{
				ans = mid;
				low = mid+1;
			}
			else if(input[mid]>= input[i]*2 && hash[mid]==true)
			{
				high = mid-1;
			}
			else if(input[mid] < input[i]*2)
			{
				low = mid+1;
			}
		}
		if(ans!=-1)
		{
			hash[i]=true;
			hash[ans]=true;
		}	}
	int f= 0;
	int t=0;
	for(int i=0;i<n;i++)
	{
		if(hash[i]==true)
		{
			t+=1;
		}
		else
		{
			f+=1;
		}
	}
	return f+(t/2);
	
}

int main()
{
	int n;
	cin >> n;
	vector<int> input(n);
	for(int i=0;i<n;i++)
	{
		cin >> input[i];
	}
	cout << solve(input,n) << endl;
	return 0;
}