#include<bits/stdc++.h>
using namespace std;


int solve(string a,string b,int m,int n)
{
	if(m==0 || n==0)
	{
		return 0;
	}
	if(a[0]==b[0] && m!=n)
	{

		return 1 + solve(a.substr(1),b.substr(1),m-1,n-1);
		
	}
	else
	{
		return max(solve(a.substr(1),b,m-1,n),solve(a,b.substr(1),m,n-1));
	}
	return 0;

}

// iterative
int solve1(string a,string b,int m,int n)
{
	int** output =new int*[m+1];
	for(int i=0;i<m+1;i++)
	{
		output[i]=new int[n+1]();
	}
	for(int i=0;i<=m;i++)
	{
		output[i][0]=0;
	}
	for(int i=0;i<=n;i++)
	{
		output[0][i]=0;
	}
	string temp="";
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[m-i]==b[n-j] && (m-i)!=(n-j))// comparing index should not be same
			{
				output[i][j]=1+output[i-1][j-1];
			}
			else
			{
				int first = output[i-1][j];
				int second = output[i][j-1];
				output[i][j]=max(first,second);
			}

		}
	}
	int i= m;
	int j = n;
	while(i>0 && j>0)
	{
		if(output[i][j]==output[i-1][j-1]+1)
		{
			// common character
			temp.push_back(a[m-i]);
			i--;
			j--;
		}
		else
		{
			if(output[i][j]==output[i-1][j])
			{
				i=i-1;
			}
			else
			{
				j=j-1;
			}
		}
	}
	int ans = output[m][n];
	for(int i=0;i<=m;i++)
	{
		delete[] output[i];
	}
	delete[] output;
	cout << temp << endl;
	return ans;
}

int main()
{
	string input;
	cin >> input;
	cout << solve(input,input,input.size(),input.size()) << endl;
	cout << solve1(input,input,input.size(),input.size()) << endl;
	return 0;
}