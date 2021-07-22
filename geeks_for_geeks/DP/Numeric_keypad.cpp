#include<bits/stdc++.h>
using namespace std;


int solve(int n)
{
	map<int,vector<int>> hash;
	hash[0].push_back(8);
	hash[0].push_back(0);
	hash[1].push_back(4);
	hash[1].push_back(1);
	hash[1].push_back(2);
	hash[2].push_back(2);
	hash[2].push_back(3);
	hash[2].push_back(5);
	hash[2].push_back(1);
	hash[3].push_back(3);
	hash[3].push_back(2);
	hash[3].push_back(6);
	hash[4].push_back(4);
	hash[4].push_back(1);
	hash[4].push_back(5);
	hash[4].push_back(7);
	hash[5].push_back(5);
	hash[5].push_back(2);
	hash[5].push_back(6);
	hash[5].push_back(4);
	hash[5].push_back(8);
	hash[6].push_back(6);
	hash[6].push_back(3);
	hash[6].push_back(5);
	hash[6].push_back(9);
	hash[7].push_back(7);
	hash[7].push_back(4);
	hash[7].push_back(8);
	hash[8].push_back(8);
	hash[8].push_back(0);
	hash[8].push_back(9);
	hash[8].push_back(7);
	hash[8].push_back(5);
	hash[9].push_back(9);
	hash[9].push_back(8);
	hash[9].push_back(6);
	int** dp = new int*[n+1];
	for(int i=0;i<=n;i++)
	{
		dp[i]=new int[10]();
	}
	for(int i=0;i<10;i++)
	{
		dp[1][i]=1;
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<10;j++)
		{
			for(int k=0;k<hash[j].size();k++)
			{
				dp[i][j]+=dp[i-1][hash[j][k]];
			}
		}
	}
	int output = 0;
	for(int i=0;i<10;i++)
	{
		
		output+=dp[n][i];
	}

	return output;


}

int main()
{
	int n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}