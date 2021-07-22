#include<bits/stdc++.h>
using namespace std;



int lcs3(string a,string b,int m,int n)
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


// recursive exponential time complexity exponential
int editDistance(string s1, string s2)
{

	// base case
	if(s1.size() == 0)
	{
		return s2.size();
	}
	if(s2.size() == 0)
	{
		return s1.size();
	}

	if(s1[0]==s2[0])
	{
		return editDistance(s1.substr(1),s2.substr(1));
	}
	// substitue
	int sub = 1 + editDistance(s1.substr(1),s2.substr(1));
	// delete
	int del = 1 + editDistance(s1.substr(1),s2);
	// insert
	int ins = 1 + editDistance(s1,s2.substr(1));

	return min(sub,min(del,ins));
}


// DP
int editDistance2(string a,string b,int** output)
{
	int sub,inse,dele;

	if(a.size()==0)
	{
		return b.size();
	}
	if(b.size()==0)
	{
		return a.size();
	}

	if(output[a.size()][b.size()] > -1)
	{
		return output[a.size()][b.size()];
	}

	if(a[0]==b[0])
	{
		output[a.size()][b.size()] = editDistance2(a.substr(1),b.substr(1),output);
	}

	else
	{
		// substitue
		sub = 1 +  editDistance2(a.substr(1),b.substr(1),output);
		// delete
		dele = 1 + editDistance2(a.substr(1),b,output);

		// insert
		inse = 1 + editDistance2(a,b.substr(1),output);

		output[a.size()][b.size()] = min(sub,min(dele,inse));
	}

	
	return output[a.size()][b.size()];

}
// iterative
int editDistance3(string a,string b,int m,int n)
{
	int** output = new int*[m+1];
	for(int i=0;i<=m;i++)
	{
		output[i] = new int[n+1];
	}

	// base case
	for(int i=0;i<=m;i++)
	{
		output[i][0] = i;
	}

	for(int i=0;i<=n;i++)
	{
		output[0][i] = i;
	}


	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(a[m-i]== b[n-j])
			{
				output[i][j] = output[i-1][j-1];
			}
			else
			{
				output[i][j] = min(output[i-1][j-1],min(output[i-1][j],output[i][j-1])) + 1;
			}
		}
	}

	int ans = output[m][n];
	for(int i=0;i<=m;i++)
	{
		delete[] output[i];
	}
	delete[] output;
	return ans;
}

int main()
{
	string a,b;
	cin >> a >> b;
	int** output = new int*[a.size()+1];
	for(int i=0;i<=a.size();i++)
	{
		output[i]=new int[b.size()+1];
		for(int j=0;j<=b.size();j++)
		{
			output[i][j]=-1;
		}
	}
	cout << editDistance3(a,b,a.size(),b.size()) << endl;
	return 0;

}
