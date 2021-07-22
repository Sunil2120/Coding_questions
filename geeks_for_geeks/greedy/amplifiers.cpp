#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
long long pow(long long a,long long b)
{
	long long output;
	if(b==0)
	{
		return 1;
	}
	if(b==1)
	{
		return a;
	}
	output = pow(a,b/2);
	if(b%2 == 0)
	{
		output = output * output;
		output%=mod;
	}
	else
	{
		output = ((output*output)%mod)*a;
		output%=mod;
	}
	return output;

}

void solve(vector<int>& arr,int n)
{
	int ones = 0;
	sort(arr.begin(),arr.end());
	long long output1=1;
	long long output2=1;
	for(int i=0;i<n;i++)
	{
		output1 = pow(arr[i],output1);
		
	}
	for(int i=n-1;i>=0;i--)
	{
		if(arr[i]==1)
		{
			break;
		}
		output2 = pow(arr[i],output2);
		
	}
	if(output1 >= output2)
	{
		for(int i=0;i<n;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	else if(output2 > output1)
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(arr[i]!=1)
			{
				break;
			}
			cout << arr[i] << " ";
		}
		for(int j=n-1;j>=i;j--)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
		
	}
	else
	{
		int i;
		for(i=0;i<n;i++)
		{
			if(arr[i]!=1)
			{
				break;
			}
			cout << arr[i] << " ";
		}
		for(int j=n-1;j>=i;j--)
		{
			cout << arr[j] << " ";
		}
		cout << endl;
	}
	return;

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
		solve(arr,n);
	}
	return 0;
}