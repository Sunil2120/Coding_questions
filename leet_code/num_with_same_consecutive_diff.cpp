
//Numbers With Same Consecutive Differences


// Return all non-negative integers of length N such that the absolute difference between every two consecutive digits is K.

// Note that every number in the answer must not have leading zeros except for the number 0 itself. For example, 01 has one leading zero and is invalid, but 0 is valid.

// You may return the answer in any order.

#include<bits/stdc++.h>
using namespace std;

void dfs(map<int,vector<int>>& hash,int start,string temp,int n,vector<int>& output)
{
	temp.push_back(start+'0');
	if(temp.size()==n)
	{
		output.push_back(stoi(temp));
		return ;
	}
	for(int i=0;i<hash[start].size();i++)
	{
		int next = hash[start][i];
		dfs(hash,next,temp,n,output);
	}
	return ;
}

void solve(int n,int k,vector<int>& output)
{
	map<int,vector<int>> hash;
	for(int i=0;i<=9;i++)
	{
		int temp1 = i+k;
		int temp2 = i-k;
		if(temp1==temp2)
		{
			hash[i].push_back(temp1);
			continue;
		}
		if(temp1 < 10)
		{
			hash[i].push_back(temp1);
		}
		if(temp2 >= 0)
		{
			hash[i].push_back(temp2);
		}
	}

	for(int i=1;i<=9;i++)
	{
		string temp;
		dfs(hash,i,temp,n,output);
	}
	return ;


	
}

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> output;
	if(n==1)//no other num to compare
	{
		for(int i=0;i<=9;i++)
		{
			output.push_back(i);
		}
	}
	if(n > 1)
	{
		solve(n,k,output);
	}
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}