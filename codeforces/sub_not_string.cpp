#include<bits/stdc++.h>
using namespace std;


bool solve(string a,string b,int index)
{
	char temp=a[index];
	a[index]='x';
	//cout << a << " " << b << endl;
	int n=a.size();
	int m=b.size();
	int** dp=new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[m+1]();
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[n-i]==b[m-j])
			{
				dp[i][j]=1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	//cout << dp[n][m] << endl;
	if(dp[n][m]==b.size())
	{
		a[index]=temp;
		for(int i=0;i<=n;i++)
		{
			delete [] dp[i];
		}
		delete [] dp;
		return true;
	}
	for(int i=0;i<=n;i++)
	{
			delete [] dp[i];
	}
	delete [] dp;
	return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,q;
		cin >> n >> q;
		string s;
		cin >> s;
		while(q--)
		{
			int l,r;
			cin >> l >> r;
			l--;
			r--;
			string check=s.substr(l,r-l+1);
			//cout << check << endl;
			int i;
			for(i=l;i<=r;i++)
			{
				
				bool temp=solve(s,check,i);
				if(temp==true)
				{
					cout << "YES" << endl;
					break;
				}
			}
			if(i>r)
			{
				cout << "NO" << endl;
			}

		}
	}
	return 0;
}