#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> input,int k,int cur,vector<int>& output)
{
	if(k==cur)
	{
		for(int i=0;i<input.size();i++)
		{
			output.push_back(input[i]);
		}
		return ;
	}
	int n= input.size();
	vector<int> temp;
	temp.push_back(1);
	for(int i=0;i<n-1;i++)
	{
		int value = input[i]+input[i+1];
		temp.push_back(value);
	}
	temp.push_back(1);
	solve(temp,k,cur+1,output);
	return ;
}

int main()
{
	int k;
	cin >> k;
	vector<int> input;
	vector<int> output;
	input.push_back(1);
	solve(input,k,0,output);
	for(int i=0;i<output.size();i++)
	{
		cout << output[i] << " ";
	}
	cout << endl;
}