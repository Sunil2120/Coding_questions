#include<bits/stdc++.h>
using namespace std;

int findceil(vector<int>& arr,int index,int n)
{
	int min_index = index+1;
	int	min_value = arr[index+1];
	for(int i=index+1;i<n;i++)
	{
		if(arr[i] > arr[index])
		{
			if(arr[i] < min_value)
			{
				min_value = arr[i];
				min_index = i;
			}
		}
	}
	return min_index;
}

int print_permutations(vector<int>& arr,int n)
{
	int done = 0;
	int max_value = INT_MIN;
	while(done==0)
	{
		int index=-1;
		
		for(int i=n-2;i>=0;i--)
		{
			if(arr[i] < arr[i+1])
			{
				index = i;
				break;
			}
		}
		if(index==-1)
		{
			done=1;
			break;
		}
		int ceil_index = findceil(arr,index,n);
		int temp = arr[index];
		arr[index] = arr[ceil_index];
		arr[ceil_index] = temp;
		vector<int> :: iterator it=arr.begin();
		for(int i=0;i<=index;i++)
		{
			it++;
		}
		reverse(it,arr.end());
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			if(i!=n-1)
			{
				sum+=abs(arr[i]-arr[i+1]);
			}
			else
			{
				sum+=abs(arr[i]-arr[0]);
			}
		}
		
		sum = max(sum,max_value);
	}
	return max_value;
}

int solve(vector<int>& arr,int n)
{
	sort(arr.begin(),arr.end());
	int i=0;
	int j=n-1;
	vector<int> output;
	int sum = 0;
	while(i<=j)
	{
		output.push_back(arr[i]);
		output.push_back(arr[j]);
		i+=1;
		j-=1;
	}
	for(int i=0;i<n;i++)
	{
		if(i!=n-1)
		{
			sum+=abs(output[i]-output[i+1]);
		}
		else
		{
			sum+=abs(output[i]-output[0]);
		}
	}
	return sum;
}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
		cin >> arr[i];
	cout << solve(arr,n) << endl;
	cout << print_permutations(arr,n) << endl;
	
	return 0;
}