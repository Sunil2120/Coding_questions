#include<bits/stdc++.h>


using namespace std;
typedef  pair<int,int> pd;



pd solve(vector<int>& arr,int low,int high)
{
	//only one element
	if(low==high)
	{
		return {arr[low],arr[high]};
	}
	// two elements
	else if(high==low+1)
	{
		if(arr[low] < arr[high])
		{
			return {arr[low],arr[high]};
		}
		else
		{
			return {arr[high],arr[low]};
		}
	}
	//else divide the array into two get min max and compare 
	
		int mid = low + (high-low)/2;
		pd temp1 = solve(arr,low,mid);
		pd temp2 = solve(arr,mid+1,high);
		
		return {min(temp1.first,temp2.first),max(temp1.second,temp2.second)};

}

int main()
{
	int n;
	cin >> n;
	vector<int> arr(n,0);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	pd res = solve(arr,0,n-1);
	cout << res.first << " " << res.second << endl;
	return 0;
}