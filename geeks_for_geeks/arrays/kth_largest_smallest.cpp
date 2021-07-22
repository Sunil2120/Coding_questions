#include<iostream>
#include<vector>

using namespace std;

// time complexity worst case O(n2) and in average case O(n)

int random_partition(vector<int>& arr,int start,int end)
{
	int key = arr[start];
	int count = 0;
	for(int i=start+1;i<=end;i++)
	{
		if(arr[i] <= key)
		{
			count+=1;
		}
	}
	int temp = arr[start];
	arr[start]=arr[start+count];
	arr[count]=temp;
	int i=start;
	int j = end;
	while(i<(start+count) && j>(start+count) && i<j)
	{
		if(arr[i] <= key)
		{
			i++;
		}
		if(arr[j] > key)
		{
			j--;
		}
		if(arr[i] > key && arr[j] <= key)
		{
			int temp = arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
		}
	}
	return start+count;
}

int solve(vector<int>& arr,int start,int end,int k)
{
	if(start < end)
	{
		int c = random_partition(arr,start,end);
		if(c==k-1)
		{
			return arr[c];
		}
		if(c > k-1)
		{
			return solve(arr,start,c-1,k);
		}
		return solve(arr,c+1,end,k);
	}
	return -1;
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,0,n-1,k) << endl;
	return 0;
}