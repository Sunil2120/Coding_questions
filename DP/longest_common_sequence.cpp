#include<bits/stdc++.h>
using namespace std;

// recurrsive method exponential
int lcs(char* a,char* b)
{
	// base case
	if(a[0]=='\0' || b[0]=='\0')// empty string
	{
		return 0;
	}
	if(a[0]==b[0])// if first characters are same will we include that character in lcs
	{
		return 1 + lcs(a+1,b+1);
	}
	// if first characters are not same
	int first = lcs(a+1,b); // including first character of first string in lcs
	int second = lcs(a,b+1); // including first character of second string in lcs
	return max(first,second);
}

int lcsHelper(char* a,char* b,int m,int n,int** dp)
{
	if(m==0 || n==0)
	{
		return 0;
	}

	if(dp[m][n] > -1)
	{
		return dp[m][n];
	}

	if(a[0]==b[0])// if first characters are same will we include that character in lcs
	{
		dp[m][n]=1+lcsHelper(a+1,b+1,m-1,n-1,dp);
	}
	else
	{
		int first = lcsHelper(a+1,b,m-1,n,dp);
		int second = lcsHelper(a,b+1,m,n-1,dp);
		dp[m][n]= max(first,second);
	}
	return dp[m][n];
}


int lcs2(char* a,char* b,int m,int n)
{
	// we are storing two information so we will use two D array
	// to represent a+1 and b+1 we will use length(a)-1 and length(b)-1
	int** dp = new int*[m+1]; 
	for(int i=0;i<=m;i++)
	{
		dp[i]=new int[n+1];
		for(int j=0;j<=n;j++)
		{
			dp[i][j]=-1; // we are intializing with -1 not with zero because lcs can be zero
		}
	}
	int ans = lcsHelper(a,b,m,n,dp);
	for(int i=0;i<=m;i++)
	{
		delete[] dp[i];
	}
	delete[] dp;
	return ans;
}

// iterative
int lcs3(char* a,char* b,int m,int n)
{
	int** output = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		output[i]=new int[n+1];
		for(int j=0;j<=n;j++)
		{
			output[i][j]=0;
		}
	}

	// base case
	for(int i=0;i<=m;i++) // if n==0
	{
		output[i][0]=0;
	}

	for(int i=0;i<=n;i++) // if m==0
	{
		output[0][i]=0;
	}

	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[m-i] == b[n-j]) // i and j means the remaining characters in str1 and str2 from the start not from the end
			{
				output[i][j] = 1 + output[i-1][j-1];
			}
			else
			{
				output[i][j] = max(output[i][j-1],output[i-1][j]);
			}
		}
	}
	int ans = output[m][n];
	for(int i=0;i<=m;i++)
	{
		delete[] output[i];
	}
	delete[]  output;
	return ans;
}

int main()
{
	char a[100];
	char b[100];
	cin >> a >> b;
	cout << lcs3(a,b,strlen(a),strlen(b)) << endl;
	cout << lcs2(a,b,strlen(a),strlen(b)) << endl;
	return 0;

}