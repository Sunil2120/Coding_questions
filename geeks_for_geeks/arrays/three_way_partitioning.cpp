#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& arr,int n,int l,int r)
{
	int low = 0;
	int high = n-1;
	int mid = 0;
	while(mid <= high)
	{
		if(arr[mid] < l)
		{
			int temp = arr[mid];
			arr[mid]=arr[low];
			arr[low]=temp;
			mid+=1;
			low+=1;
		}
		else if(arr[mid] >= l && arr[mid] <= r)
		{
			mid+=1;
		}
		else
		{
			int temp = arr[mid];
			arr[mid]=arr[high];
			arr[high]=temp;
			high--;
		}
	}
	return ;
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
	int l,r;
	cin >> l >> r;
	solve(arr,n,l,r);
	for(int i=0;i<n;i++)
	{
		cout <<  arr[i] << " ";
	}
	cout << endl;

	return 0;
}