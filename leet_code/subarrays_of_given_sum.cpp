// to find all subarrays which sums up to given sum


#include<bits/stdc++.h>
using namespace std;
// without overlapping
// total subarray sum - subarray sum to be subtracted = target sum
int solve(int* arr,int n,int k)
{
	if(n==0)
	{
		return 0;
	}
	set<int> prefix;
	prefix.insert(0);// first element same as target can appear
	int sum = 0;
	int count = 0;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(prefix.find(sum-k)!=prefix.end())// there is a subarray of given sum
		{
			count+=1;
			// to avoid overlapping
			prefix.erase(0);
		}
		prefix.insert(sum);
	}
	return count;

}

int main()
{
	int n;
	int k;
	cin >> n >> k;
	int* arr = new int[n];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,k) << endl;
}