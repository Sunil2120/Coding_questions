#include<bits/stdc++.h>
using namespace std;


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



int smallestSuperSequence(char str1[], int len1, char str2[], int len2) 
{ 
 	int lcs = lcs3(str1,str2,len1,len2);
 	int result = lcs + len1-lcs + len2 - lcs;
 	return result;
}