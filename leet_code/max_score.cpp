#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007


long long solve(int* arr,int* arr1,int n,int m)
{
	long long total = 0;
	long long i=0;
	long long j=0;
	long long prev1 =0;
	long long prev2 = 0;
	while(i<n && j < m)
	{
		//cout << "hello" <<endl;
		if(arr[i]==arr1[j])
		{

			total+=max(prev1+arr[i],prev2+arr1[j]);
			total=total%MOD;
			cout << prev1+arr[i] << " " << prev2+arr1[j] << endl;
			prev1 = 0;
			prev2 = 0;
			i++;
			j++;
		}
		else if(arr[i] < arr1[j])
		{
			prev1+=arr[i];
			//prev2+=arr1[j];
			i++;
		}
		else
		{
			//prev1+=arr[i];
			prev2+=arr1[j];
			j++;
		}
	}
	while(i<n)
	{
		prev1+=arr[i];
		i++;
	}
	while(j<m)
	{
		prev2+=arr1[j];
		j++;
	}
	total += max(prev1,prev2);
	total=total%MOD;
	return total;
}

int main()
{
	int n,m;
	cin >> n >> m;
	int* arr = new int[n];
	int* arr1 = new int[m];
	for(int i=0;i<n;i++)
	{
		cin >> arr[i];
	}
	for(int i=0;i<m;i++)
	{
		cin >> arr1[i];
	}
	// we will use merge like function
	cout << solve(arr,arr1,n,m) << endl;
	return 0;
}