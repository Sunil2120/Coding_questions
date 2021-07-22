#include<bits/stdc++.h>
using namespace std;


int solve(long long a,string b,int c)
{
	long long ans = a;
	long long result = 1;
	for(int i=b.length()-1;i>=0;i--)
	{
		if(b[i]=='0')
		{
			ans = ((ans*ans)%c*ans)%c;
		}
		else if(b[i]=='1')
		{
			result = (result*ans)%c;
			ans = ((ans*ans)%c*ans)%c;
		}
		else
		{
			result = (result*ans)%c;
			result = (result*ans)%c;
			ans = ((ans*ans)%c*ans)%c;
		}
	}
	return (int)result;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		long long a;
		string b;
		int c;
		cin >> a >> b >> c;
		cout << solve(a,b,c) << endl;
	}
}