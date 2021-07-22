#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int solve(vector<int>& arr,int n,int k)
{
	if(n==0)
	{
		return 0;
	}
	int count = 0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]<= k)
		{
			count+=1;
		}
	}
	int i=0;
	int output = INT_MAX;
	while(i<n)
	{
		int next = count+i-1;
		if(next >= n)
		{
			return output;
		}
		int temp = 0;
		for(int j=0;j<=next;j++)
		{
			if(arr[j] > k)
			{
				temp+=1;
			}
		}
		output = min(output,temp);
		i+=1;
	}
	return output;

}


int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	cout << solve(arr,n,k) << endl;
	return 0;
}

