#include<bits/stdc++.h>
using namespace std;


int solve(string a,string b,int m,int n,int k)
{
	if(m==0 || n==0)
	{
		return 0;
	}
	if(k==0)
	{
		return 0;
	}
	if(k<0)
	{
		return INT_MIN;
	}
	// if characters are equal
	if(a[0]==b[0])
	{
		// include
		int temp1 = solve(a.substr(1),b.substr(1),m-1,n-1,k-1) + a[0];
		// if function fails to bring enough characters for i+1,j+1
		if(solve(a.substr(1),b.substr(1),m-1,n-1,k-1)==0 && k>1)
		{
			temp1 = 0;
		}
		// we are not including 
		int temp2 = solve(a.substr(1),b.substr(1),m-1,n-1,k);
		// we are just considering first character of first string
		int temp3 = solve(a,b.substr(1),m,n-1,k);
		// we are just considering first character of second string
		int temp4 = solve(a.substr(1),b,m-1,n,k);
		return max(temp1,max(temp2,max(temp3,temp4)));
	}
	// if first characters are not same we have two choice
	return max(solve(a,b.substr(1),m,n-1,k),solve(a.substr(1),b,m-1,n,k));

}


int solve2(string a,string b,int m,int n,int k)
{
	//cout << "hello1" << endl;
	// we are storing three information k m n so 3D array
	int*** output = new int**[m+1];
	for(int i=0;i<=m;i++)
	{
		output[i]=new int*[n+1];
		for(int j=0;j<=n;j++)
		{
			output[i][j]=new int[k+1];
		}
	}
	// m==0
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			output[0][i][j]=0;
		}
	}

	// n=0;
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=k;j++)
		{
			output[i][0][j]=0;
		}
	}

	//k=0

	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			output[i][j][0]=0;
		}
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int h=1;h<=k;h++)
			{
				// if same
				if(a[m-i]==b[n-j])
				{
					//cout << "hello" << endl;
					int temp1 = output[i-1][j-1][h-1] + a[m-i];
					if(output[i-1][j-1][h-1]==0 && h > 1)
					{
						temp1=0;
					}
					int temp2 = output[i-1][j-1][h];
					int temp3 = output[i-1][j][h];
					int temp4 = output[i][j-1][h];
					output[i][j][h] = max(temp1,max(temp2,max(temp3,temp4)));
					//cout << output[i][j][h]<< endl;
				}
				else
				{
					output[i][j][h]=max(output[i-1][j][h],output[i][j-1][h]);
					//cout << output[i][j][h]<< endl;
				}
			}
		}
	}
	int ans = output[m][n][k];
	delete[] output;
	return ans;


}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string a,b;
		cin >> a >> b;
		int k;
		cin >> k;
		cout << solve(a,b,a.size(),b.size(),k) << endl;
		cout << solve2(a,b,a.size(),b.size(),k) << endl;
	}
	return 0;
}