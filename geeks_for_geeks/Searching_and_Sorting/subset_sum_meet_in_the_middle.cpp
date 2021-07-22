#include<bits/stdc++.h>
using namespace std;


long long solve(vector<long long>& arr,int n,long long A,long long B)
{
	if(n==0)
	{
		return 0;
	}
}

int main()
{
	int n;
	long long A,B;
	cin >> n >> A >> B;
	vector<long long> arr(n);
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	cout << solve(arr,n,A,B) << endl;
	return 0;
}